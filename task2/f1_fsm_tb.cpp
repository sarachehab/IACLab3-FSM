#include "Vf1_fsm.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"

int main(int argc, char **argv, char **env)
{

    int tick;
    int simcyc;

    Verilated::commandArgs(argc, argv);

    // init top veriloginstance
    Vf1_fsm *top = new Vf1_fsm;

    // init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("f1_fsm.vcd");

    // init Vbuddy
    if (vbdOpen() != 1)
        return (-1);
    vbdHeader("LAB 3: F1 FSM");

    // set one shot behaviour for flag
    vbdSetMode(1);

    // init simulation inputs
    top->clk = 1;
    top->rst = 1;
    top->en = 0;

    // run simulation
    for (simcyc = 0; simcyc < 10000; simcyc++)
    {
        for (tick = 0; tick < 2; tick++)
        {
            tfp->dump(2 * simcyc + tick);
            top->clk = !top->clk;
            top->eval();
        }

        // display on Vbuddy
        vbdBar(top->data_out);
        vbdHex(2, (top->data_out >> 4) & 0xF);
        vbdHex(1, top->data_out & 0xF);
        vbdCycle(simcyc);

        // get input for enable
        top->en = vbdFlag();
        top->rst = simcyc < 2;

        if (Verilated::gotFinish() || vbdGetkey() == 'q')
            exit(0);
    }

    vbdClose();
    tfp->close();
    exit(0);
}
#include "Vlfsr.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"

int main(int argc, char **argv, char **env)
{
    int i;
    int clk;

    Verilated::commandArgs(argc, argv);
    // init top Verilog instance
    Vlfsr *top = new Vlfsr;
    // init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("lfsr.vcd");

    // init Vbuddy
    if (vbdOpen() != 1)
        return -1;
    vbdHeader("Lab 3: LFSR");

    // set one-shot mode for flag
    vbdSetMode(1);

    // initalize simulation inputs
    top->clk = 1;
    top->rst = 1;
    top->en = 0;

    // run simulation
    for (int simcyc = 0; simcyc < 10000; simcyc++)
    {

        // for dump variables into VCD file and toggle clock
        for (clk = 0; clk < 2; clk++)
        {
            tfp->dump(2 * simcyc + clk);
            top->clk = !top->clk;
            top->eval();
        }

        // output data_out on 7-segment display and neopixel strip
        vbdHex(2, (top->data_out >> 4) & 0xF);
        vbdHex(1, top->data_out & 0xF);
        vbdBar(top->data_out & 0xFF); // mask data_out with 0xFF since vbdBar() takes 8 bit inputs
        vbdCycle(simcyc);

        // change input simulation
        top->rst = simcyc < 2;
        top->en = vbdFlag();

        if (Verilated::gotFinish() || vbdGetkey() == 'q')
            exit(0);
    }

    vbdClose();
    tfp->close();
    exit(0);
}
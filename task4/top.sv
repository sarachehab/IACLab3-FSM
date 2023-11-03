module top # (
    parameter   N_WIDTH = 16,
                N_LEDS = 8,
                RANDOM_WIDTH = 10,
)(
    input                   clk,
    input                   rst,
    input                   trigger,
    input   [N_WIDTH-1:0]   N,
    output  [N_LEDS-1:0]    data_out
);
    logic cmd_seq;
    logic cmd_delay;

    logic   [RANDOM_WIDTH-1:0]  random_number;
    logic   leds_prepare;
    logic   leds_off;

    lfsr random_generator (
        .clk(clk),
        .data_out(random_number)
    );

    delay turn_off (
        .clk(clk),
        .rst(rst),
        .trigger(cmd_delay),
        .n(random_numer),
        .time_out(leds_off)
    );

    clktick prepare (
        .N(N),
        .en(cmd_seq),
        .rst(rst),
        .clk(clk),
        .tick(leds_prepare)
    );

    f1_fsm game (
        .rst(rst),
        .en(cmd_sequence ? leds_prepare : leds_off),
        .trigger(trigger),
        .clk(clk),
        .data_out(data_out),
        .cmd_seq(cmd_seq),
        .cmd_delay(cmd_delay)
    );

endmodule


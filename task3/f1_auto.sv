module f1_auto (
    input           clk,
    input           rst,
    input   [15:0]  N,
    output  [7:0]   data_out
);
    logic light_trigger;

    clktick second_delay (
        .N(N),
        .en(1),
        .rst(rst),
        .clk(clk),
        .tick(light_trigger)
    );

    f1_fsm f1_lights (
        .rst(rst),
        .en(light_trigger),
        .clk(clk),
        .data_out(data_out)
    );

endmodule


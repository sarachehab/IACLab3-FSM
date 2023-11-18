module lfsr #(
    parameter WIDTH = 8
)(
    input               clk,
    input               en,
    input               rst,
    output  [WIDTH-1:0] data_out
);
    logic   [WIDTH:1]   sreg;

    always_ff @(posedge clk, posedge rst)

        if (rst)
            sreg <= 8'b1;
        else if (en)
            sreg <= {sreg[WIDTH-1:1], sreg[WIDTH-1]^sreg[WIDTH]};

    assign data_out = sreg;

endmodule

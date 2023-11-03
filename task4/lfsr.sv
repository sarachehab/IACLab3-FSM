module lfsr #(
    parameter WIDTH = 8
)(
    input               clk,
    output  [WIDTH-1:0] data_out
);
    logic   [WIDTH:1]   sreg = 4'b1;

    always_ff @(posedge clk, posedge rst)
        sreg <= {sreg[WIDTH-1:1], sreg[WIDTH-1]^sreg[WIDTH]};

    assign data_out = sreg;

endmodule
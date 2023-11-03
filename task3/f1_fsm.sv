module f1_fsm (
    input           clk,
    input           rst,
    input           en,
    output  [7:0]   data_out
);

    // define states
    typedef enum {S0, S1, S2, S3, S4, S5, S6, S7, S8} my_state;
    my_state current_state, next_state;

    logic [7:0] out;

    // state transition
    always_ff @ (posedge clk, posedge rst)

        if (rst)
            current_state <= S0;
        else if (en)
            current_state <= next_state;
        
        // next state logic
        always_comb
            case (current_state)
                S0: next_state = S1;
                S1: next_state = S2;
                S2: next_state = S3;
                S3: next_state = S4;
                S4: next_state = S5;
                S5: next_state = S6;
                S6: next_state = S7;
                S7: next_state = S8;
                S8: next_state = S0;
                default: next_state = S0;
            endcase

        // next state logic
        always_comb
            case (current_state)
                S0: out = 8'b0;
                S1: out[0] = 1'b1;
                S2: out[1] = 1'b1;
                S3: out[2] = 1'b1;
                S4: out[3] = 1'b1;
                S5: out[4] = 1'b1;
                S6: out[5] = 1'b1;
                S7: out[6] = 1'b1;
                S8: out[7] = 1'b1;
                default: out = 8'b0;
            endcase

    assign data_out = out;

endmodule


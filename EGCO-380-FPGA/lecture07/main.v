module main(
	input CLK12MHZ,
	input [0:0] btn,
	input [3:0] sw,
    output wire [6:0] ja,
    output wire [3:0] jb,
    output wire [1:0] led);
    
    reg[23:0] clk = 0;
    always @(posedge CLK12MHZ)
        clk <= clk + 1;
    
    top_wrapper top_0(
        clk,
        led[0],
        sw,
        led[1],
        btn[0],
        ja
    );
    
endmodule 
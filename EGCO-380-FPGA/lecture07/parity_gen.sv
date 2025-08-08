module parity_gen (
  input [7:0] in,
  output odd,
  output even
);

  wire parity_val;

  // Calculate parity by XORing all input bits
  assign parity_val = ^in; // XOR reduction operator

  // Odd parity output is the parity value itself
  assign odd = parity_val;

  // Even parity output is the inverse of the parity value
  assign even = ~parity_val;

endmodule
//------------------------------------------------
// mipstest.v
// David_Harris@hmc.edu 23 October 2005
// Testbench for MIPS processor
//------------------------------------------------

module tb( );
 // output herp;
  reg         clk;
  reg         reset;
  // wire [31:0] writedata, dataadr;
  wire		[31:0] 	pc, instr, dataadr, writedata, readdata, dispDat;
  wire 					clksec;
  wire 					memwrite;
  wire		[ 7:0]	switches;
  // instantiate device to be tested
  //top dut(clk, reset, writedata, dataadr, memwrite);
   mips 	mips	(clk, reset, pc, instr, 
					memwrite, dataadr, writedata, readdata, switches[4:0], dispDat);
	imem 	imem	(pc[8:2], instr);
	dmem	dmem	(clk, memwrite, dataadr, writedata, readdata);
//  module mips(
//	input        	clk, reset,
//	output	[31:0]	pc,
//	input 	[31:0]	instr,
//	output			memwrite,
//	output	[31:0]	aluout, writedata,
//	input 	[31:0]	readdata,
//	input	[ 4:0]	dispSel,
//	output	[31:0]	dispDat );
	
  // initialize test
  initial
    begin
      reset <= 1; # 22; reset <= 0;
    end

  // generate clock to sequence tests
  always
    begin
      clk <= 1; # 5; clk <= 0; # 5;
    end

  // check that 7 gets written to address 84
  always@(negedge clk)
    begin
      if(memwrite) begin
        if(dataadr === 84 & writedata === 7) begin
          $display("Simulation succeeded");
          //$stop;
        end else if (dataadr !== 80) begin
          $display("Simulation failed");
          //$stop;
        end
      end
    end
endmodule




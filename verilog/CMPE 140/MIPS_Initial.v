//-----------------------------------------------------------------
// Module Name   : clk_gen
// Description   : Generate 4 second and 5KHz clock cycle from
//                 the 50MHz clock on the Nexsys2 board
//------------------------------------------------------------------
module clk_gen(
	input			clk50MHz, reset, 
	output reg		clksec );

	reg 			clk_5KHz;
	integer 		count, count1;
	
	always@(posedge clk50MHz) begin
		if(reset) begin
			count = 0;
			count1 = 0;
			clksec = 0;
			clk_5KHz =0;
		end else begin
			if (count == 500000000) begin
				// Just toggle after certain number of seconds
				clksec = ~clksec;
				count = 0;
			end
			if (count1 == 20000) begin
				clk_5KHz = ~clk_5KHz;
				count1 = 0;
			end
			count = count + 1;
			count1 = count1 + 1;
		end
	end
endmodule

//------------------------------------------------
// Source Code for a Single-cycle MIPS Processor (supports partial instruction)
// Developed by D. Hung, D. Herda and G. Gerken,
// based on the following source code provided by
// David_Harris@hmc.edu (9 November 2005):
//    mipstop.v
//    mipsmem.v
//    mips.v
//    mipsparts.v
//------------------------------------------------

// Main Decoder
module maindec(
	input	[ 5:0]	op,
	output			memtoreg, memwrite, branch, alusrc, regdst, regwrite, jump,
	output	[ 1:0]	aluop,
	output jalSel);

	reg 	[ 9:0]	controls;
	initial
		begin
			controls = 0;
		end
		
	assign {jalSel, regwrite, regdst, alusrc, branch, memwrite, memtoreg, jump, aluop} = controls;

	always @(*)
		case(op)
			6'b000000: controls <= 10'b0110000010; //Rtype + jr
			6'b100011: controls <= 10'b0101001000; //LW|regwrite|alursrc|memtoreg
			6'b101011: controls <= 10'b0001010000; //SW-
			6'b000100: controls <= 10'b0000100001; //BEQ
			6'b001000: controls <= 10'b0101000000; //ADDI
			6'b000010: controls <= 10'b0000000100; //J 
			6'b000011: controls <= 10'b1100000100; //JAL
			default:   controls <= 10'b0000000000; //???
		endcase
endmodule

// ALU Decoder
module aludec(
	input		[5:0]	funct,
	input		[1:0]	aluop,
	output reg	[2:0]	alucontrol,	
	output reg jumpreg,
	output reg  [1:0] regWriteSel,
	output reg writeHiLoreg
	);

	always @(*)
		case(aluop)
			2'b00: alucontrol <= 3'b010;  // add
			2'b01: alucontrol <= 3'b110;  // sub
			default: case(funct)          // RTYPE
				6'b100000: begin
								alucontrol <= 3'b010; // ADD
								jumpreg 	  <= 1'b0;
								regWriteSel   <= 2'b00;
								writeHiLoreg <= 1'b0;
								end
				6'b100010: begin
								alucontrol <= 3'b110; // SUB
								jumpreg 	  <= 1'b0;
								regWriteSel   <= 2'b00;
								writeHiLoreg <= 1'b0;
								end
				6'b100100: begin
								alucontrol <= 3'b000; // AND
								jumpreg 	  <= 1'b0;
								regWriteSel   <= 2'b00;
								writeHiLoreg <= 1'b0;
								end
				6'b100101: begin
								alucontrol <= 3'b001; // OR
								jumpreg 	  <= 1'b0;
								regWriteSel   <= 2'b00;
								writeHiLoreg <= 1'b0;
								end
				6'b101010: begin
								alucontrol <= 3'b111; //SLT								
								jumpreg 	  <= 1'b0;
								regWriteSel   <= 2'b00;
								writeHiLoreg <= 1'b0;
								end
				6'b001000: begin
							  jumpreg 	 <= 1'b1;	// JR
							  alucontrol <= 3'bxxx; // ???
							  regWriteSel   <= 2'b00;
								writeHiLoreg <= 1'b0;
							  end							  
				6'b011000: begin
							  jumpreg 	 <= 1'b0;	// MULT		
							  alucontrol <= 3'b011;							  
							  regWriteSel   <= 2'b00;
							  writeHiLoreg <= 1'b1;
							  end				  
				6'b010000: begin
							  jumpreg 	 <= 1'b0;	// MFHI		
							  alucontrol <= 3'bxxx; // ???							  
							  regWriteSel   <= 2'b01;
							  writeHiLoreg <= 1'b0;
							  end
				6'b010010: begin
							  jumpreg 	 <= 1'b0;	// MFLO		
							  alucontrol <= 3'bxxx; // ???							  
							  regWriteSel   <= 2'b10;
							  writeHiLoreg <= 1'b0;
							  end								  
							  
				default:   begin
							  alucontrol <= 3'b000; // ???
							  jumpreg 	  <= 1'b0;
							  regWriteSel   <= 2'b00;
							  writeHiLoreg <= 2'b00;
							  end
			endcase
		endcase
endmodule
// ALU
module alu(
	input		[31:0]	a, b, 
	input		[ 2:0]	alucont, 
	output reg	[31:0]	result,
	output reg	[31:0]  resultExt,
	output			zero );

	wire	[31:0] sum, slt;
	
	//	wire	[31:0]	b2;
	//assign b2 = alucont[2] ? ~b:b; // no idea what this is for
	//assign sum = a + b2 + alucont[2];
	assign sum = a + b;
		
	//assign slt = sum[31];
	
	assign slt = (a < b ? 32'h0001 : 32'h0000);
	
	initial
		begin
			result <= 32'b0;
			resultExt <= 32'b0;
		end

	always@(*)
		case(alucont[2:0]) // open remaining: 011, 100, 101, 110(sub)
			3'b000: begin
					result <= a & b; 
					resultExt <= 32'b0;
					end
			3'b001: begin
					result <= a | b; 
					resultExt <= 32'b0;
					end
			3'b010: begin
					result <= sum; 
					resultExt <= 32'b0;
					end
			3'b110: begin
					result <= a-b;
					resultExt <= 32'b0;
					end
			3'b111: begin
					result <= slt;
					resultExt <= 32'b0;
					end
			3'b011: {resultExt, result} <= a * b; // unsure if this works
		endcase

	assign zero = (result == 32'b0);
endmodule

module smallReg(
	input	clk, writeEnable,
	input	[31:0]	reg_input,
	output 	[31:0]	reg_out
	);
	reg		[31:0] 	reg_val;
	initial
		begin
		reg_val = 32'b0;
		end
	always @ (posedge clk)
		begin
			if( writeEnable == 1'b1 ) 
				begin
					reg_val <= reg_input;		
				end
		end		
	assign reg_out = (reg_val != 0) ? reg_val : 0;
endmodule

// Pipilened registers
module pipelineReg_IF_ID(
	input	clk, 
	// Datapath Inputs
	input	[31:0]	instr_IF,
	input	[31:0]	pcplus4_IF,	
	// Datapath Outputs
	output 	[31:0]	instr_ID,
	output 	[31:0]	pcplus4_ID
	);
	
	reg		[31:0] 	instr, pc;
	initial
		begin
		instr = 32'b0;
		pc = 32'b0;
		end
	always @ (posedge clk)
		begin
				instr <= instr_IF;
				pc		<= pcplus4_IF;
		end		
		
	assign instr_ID = (instr != 0) ? instr : 0;
	assign pcplus4_ID = (pc != 0) ? pc : 0;
endmodule

module pipelineReg_ID_EX(
	input	clk,
	// Control Inputs
	input jalSel_ID,
			regwrite_ID,
			regdst_ID,
			alusrc_ID,
			memwrite_ID,
			memtoreg_ID,
	input [2:0] alucontrol_ID,
	input [1:0] regWriteSel_ID,
	input writeHiLoreg_ID,
	// Datapath Inputs
	input	[31:0]	srca_ID,
	input	[31:0]	writedata_ID,	
	input [4:0]		instr_20_16_ID,
	input [4:0]		instr_15_11_ID,
	input [31:0]	signimm_ID,
	input [31:0]	pcplus4_ID,
	// Control outputs
	output jalSel_EX,
			regwrite_EX,
			regdst_EX,
			alusrc_EX,
			memwrite_EX,
			memtoreg_EX,
	output [2:0] alucontrol_EX,
	output [1:0] regWriteSel_EX,
	output writeHiLoreg_EX,
	// Datapath outputs
	output	[31:0]	srca_EX,
	output	[31:0]	writedata_EX,	
	output [4:0]		instr_20_16_EX,
	output [4:0]		instr_15_11_EX,
	output [31:0]	signimm_EX,
	output [31:0]	pcplus4_EX
	);
	
	//Control regs
	reg		 jalSel, regwrite, regdst, alusrc, memwrite, memtoreg;
	reg [2:0] alucontrol, regWriteSel;
	reg		 writeHiLoreg;
	// Datapath regs
	reg [31:0] srca, writedata;
	reg [4:0]  instr_20_16, instr_15_11;
	reg [31:0] signimm, pcplus4;
	initial
		begin
		jalSel = 0;
		regwrite = 0;
		regdst = 0;
		alusrc = 0;
		memwrite = 0;
		memtoreg = 0;
		alucontrol = 0;
		regWriteSel = 0;
		writeHiLoreg = 0;
		srca = 0;
		writedata = 0;
		instr_20_16 = 0;
		instr_15_11 = 0;
		signimm = 0;
		pcplus4 = 0;
		end
	always @ (posedge clk)
		begin
			jalSel <= jalSel_ID;
			regwrite <= regwrite_ID;
			regdst <= regdst_ID;
			alusrc <= alusrc_ID;
			memwrite <= memwrite_ID;
			memtoreg <= memtoreg_ID;
			alucontrol <= alucontrol_ID;
			regWriteSel <= regWriteSel_ID;
			writeHiLoreg <= writeHiLoreg_ID;
			srca <= srca_ID;
			writedata <= writedata_ID;
			instr_20_16 <= instr_20_16_ID;
			instr_15_11 <= instr_15_11_ID;
			signimm <= signimm_ID;
			pcplus4 <= pcplus4_ID;
		end		
		
	assign jalSel_EX = (jalSel != 0) ? jalSel : 0;
	assign regwrite_EX = (regwrite != 0) ? regwrite : 0;
	assign regdst_EX = (regdst != 0) ? regdst : 0;
	assign alusrc_EX = (alusrc != 0) ? alusrc : 0;
	assign memwrite_EX = (memwrite != 0) ? memwrite : 0;
	assign memtoreg_EX = (memtoreg != 0) ? memtoreg : 0;
	assign alucontrol_EX = (alucontrol != 0) ? alucontrol : 0;
	assign regWriteSel_EX = (regWriteSel != 0) ? regWriteSel : 0;
	assign writeHiLoreg_EX = (writeHiLoreg != 0) ? writeHiLoreg : 0;
	assign srca_EX = (srca != 0) ? srca : 0;
	assign writedata_EX = (writedata != 0) ? writedata : 0;
	assign instr_20_16_EX = (instr_20_16 != 0) ? instr_20_16 : 0;
	assign instr_15_11_EX = (instr_15_11 != 0) ? instr_15_11 : 0;
	assign signimm_EX = (signimm != 0) ? signimm : 0;
	assign pcplus4_EX = (pcplus4 != 0) ? pcplus4 : 0;
endmodule

module pipelineReg_EX_MEM(
	input	clk,
	// Control Inputs
	input jalSel_EX,
			regwrite_EX,
			memwrite_EX,
			memtoreg_EX,
			writeHiLoreg_EX,
	input [1:0] regWriteSel_EX,
	// DataPath Inputs
	input [31:0] aluout_EX,
	input [31:0] aluoutExt_EX,
	input [31:0] writedata_EX,
	input [4:0]  writereg_EX,
	input [31:0] pcplus4_EX,
	// Control Ouputs
	output jalSel_MEM,
			regwrite_MEM,
			memwrite_MEM,
			memtoreg_MEM,
			writeHiLoreg_MEM,
	output [1:0] regWriteSel_MEM,
	// DataPath Outputs
	output [31:0] aluout_MEM,
	output [31:0] aluoutExt_MEM,
	output [31:0] writedata_MEM,
	output [4:0]  writereg_MEM,
	output [31:0] pcplus4_MEM
	);
	
	reg jalSel, regwrite, memwrite, memtoreg, writeHiLoreg;
	reg [1:0] regWriteSel;
	reg [31:0] aluout, aluoutExt, writedata;
	reg [4:0] writereg;
	reg [31:0] pcplus4;
	initial
		begin
		jalSel = 0;
		regwrite = 0;
		memwrite = 0;
		memtoreg = 0;
		writeHiLoreg = 0;
		regWriteSel = 0;
		aluout = 0;
		aluoutExt = 0;
		writedata = 0;
		writereg = 0;
		pcplus4 = 0;
		end
	always @ (posedge clk)
		begin
			jalSel   <= jalSel_EX;
			regwrite <= regwrite_EX;
			memwrite <= memwrite_EX;
			memtoreg <= memtoreg_EX;
			writeHiLoreg <= writeHiLoreg_EX;
			regWriteSel <= regWriteSel_EX;
			aluout <= aluout_EX;
			aluoutExt <= aluoutExt_EX;
			writedata <= writedata_EX;
			writereg <= writereg_EX;
			pcplus4 <= pcplus4_EX;
		end		
		
	assign jalSel_MEM = (jalSel != 0) ? jalSel : 0;
	assign regwrite_MEM = (regwrite != 0) ? regwrite : 0;
	assign memwrite_MEM = (memwrite != 0) ? memwrite : 0;
	assign memtoreg_MEM = (memtoreg != 0) ? memtoreg : 0;
	assign writeHiLoreg_MEM = (writeHiLoreg != 0) ? writeHiLoreg : 0;
	assign regWriteSel_MEM = (regWriteSel != 0) ? regWriteSel : 0;
	assign aluout_MEM = (aluout != 0) ? aluout : 0;
	assign aluoutExt_MEM = (aluoutExt != 0) ? aluoutExt : 0;
	assign writedata_MEM = (writedata != 0) ? writedata : 0;
	assign writereg_MEM = (writereg != 0) ? writereg : 0;
	assign pcplus4_MEM = (pcplus4 != 0) ? pcplus4 : 0;
endmodule


module pipelineReg_MEM_WB(
	input	clk,
	// Control Inputs
	input jalSel_MEM,
			regwrite_MEM,
			memtoreg_MEM,
	input [1:0] regWriteSel_MEM,
	// Datapath Inputs
	input [31:0] readdata_MEM,
	input [31:0] aluout_MEM,
	input [31:0] readhi_MEM,
	input [31:0] readlo_MEM,
	input [4:0] writereg_MEM,
	input [31:0] pcplus4_MEM,
	// Control Outputs
	output 	jalSel_WB,
				regwrite_WB,
				memtoreg_WB,
	output [1:0] regWriteSel_WB,
	// Datapath Outputs
	output [31:0] readdata_WB,
	output [31:0] aluout_WB,
	output [31:0] readhi_WB,
	output [31:0] readlo_WB,
	output [4:0] writereg_WB,
	output [31:0] pcplus4_WB	
	);
	
	reg jalSel, regwrite, memtoreg;
	reg [1:0] regWriteSel;
	reg [31:0] readdata, aluout, readhi, readlo;
	reg [4:0] writereg;
	reg [31:0] pcplus4;
	
	initial
		begin
		jalSel = 0;
		regwrite = 0;
		memtoreg = 0;
		regWriteSel = 0;
		readdata = 0;
		aluout = 0;
		readhi = 0;
		readlo = 0;
		writereg = 0;
		pcplus4 = 0;
		end
	always @ (posedge clk)
		begin
			jalSel <= jalSel_MEM;
			regwrite <= regwrite_MEM;
			memtoreg <= memtoreg_MEM;
			regWriteSel <= regWriteSel_MEM;
			readdata <= readdata_MEM;
			aluout <= aluout_MEM;
			readhi <= readhi_MEM;
			readlo <= readlo_MEM;
			writereg <= writereg_MEM;
			pcplus4 <= pcplus4_MEM;
		end		
		
	assign jalSel_WB = (jalSel != 0) ? jalSel : 0;
	assign regwrite_WB = (regwrite != 0) ? regwrite : 0;
	assign memtoreg_WB = (memtoreg != 0) ? memtoreg : 0;
	assign regWriteSel_WB = (regWriteSel != 0) ? regWriteSel : 0;
	assign readdata_WB = (readdata != 0) ? readdata : 0;
	assign aluout_WB = (aluout != 0) ? aluout : 0;
	assign readhi_WB = (readhi != 0) ? readhi : 0;
	assign readlo_WB = (readlo != 0) ? readlo : 0;
	assign writereg_WB = (writereg != 0) ? writereg : 0;
	assign pcplus4_WB = (pcplus4 != 0) ? pcplus4 : 0;
endmodule

// Adder
module adder(
	input	[31:0]	a, b,
	output	[31:0]	y );

	assign y = a + b;
endmodule

// Two-bit left shifter
module sl2(
	input	[31:0]	a,
	output	[31:0]	y );

	// shift left by 2
	assign y = {a[29:0], 2'b00};
endmodule

// Sign Extension Unit
module signext(
	input	[15:0]	a,
	output	[31:0]	y );

	assign y = {{16{a[15]}}, a};
endmodule

// Parameterized Register
module flopr #(parameter WIDTH = 8) (
	input		clk, reset,
	input		[WIDTH-1:0]	d, 
	output reg	[WIDTH-1:0]	q);

	always @(posedge clk, posedge reset)
		if (reset) q <= 0;
		else       q <= d;
endmodule

// commented out since flopenr is not used
//module flopenr #(parameter WIDTH = 8) (
//	input					clk, reset,
//	input					en,
//	input		[WIDTH-1:0]	d, 
//	output reg	[WIDTH-1:0]	q);
//
//	always @(posedge clk, posedge reset)
//		if      (reset) q <= 0;
//		else if (en)    q <= d;
//endmodule

// Parameterized 2-to-1 MUX
module mux2 #(parameter WIDTH = 8) (
	input	[WIDTH-1:0]	d0, d1, 
	input				s, 
	output	[WIDTH-1:0]	y );

	assign y = s ? d1 : d0; 
endmodule

// Parameterized 4-to-1 MUX
module mux4 #(parameter WIDTH = 8) (
	input	[WIDTH-1:0]	d0, d1, d2, d3, 
	input	 [1:0]	s, 
	output reg	[WIDTH-1:0]	y );

always @(*)
begin
	case(s)
		2'b00: y = d0;
		2'b01: y = d1;
		2'b10: y = d2;
		2'b11: y = d3;
		
	endcase
end
endmodule

// register file with one write port and three read ports
// the 3rd read port is for prototyping dianosis
module regfile(	
	input			clk, 
	input			we3, 
	input 	[ 4:0]	ra1, ra2, wa3, 
	input	[31:0] 	wd3, 
	output 	[31:0] 	rd1, rd2,
	input	[ 4:0] 	ra4,
	output 	[31:0] 	rd4);

	reg		[31:0]	rf[31:0];
	integer			n;
	
	//initialize registers to all 0s
	initial 
		begin
		for (n=0; n<32; n=n+1) 
			begin
			rf[n] = 32'h00;
			end
		rf[n-3] = 32'h100;
		end
			
	//write first order, include logic to handle special case of $0
    always @(posedge clk)

        if (we3)
			if (wa3 == 5'b00000);
			else if (~ wa3[4])
				rf[{1'b0,wa3[3:0]}] <= wd3;
			else
				rf[{1'b1,wa3[3:0]}] <= wd3;
		
			
		
			// this leads to 72 warnings
			//rf[wa3] <= wd3;
			
			// this leads to 8 warnings
			//if (~ wa3[4])
			//	rf[{0,wa3[3:0]}] <= wd3;
			//else
			//	rf[{1,wa3[3:0]}] <= wd3;
		
	assign rd1 = (ra1 != 0) ? rf[ra1[4:0]] : 0;
	assign rd2 = (ra2 != 0) ? rf[ra2[4:0]] : 0;
	assign rd4 = (ra4 != 0) ? rf[ra4[4:0]] : 0;
endmodule

// Control Unit
module controller(
	input	[5:0]	op, funct,
	input			zero,
	
	output			memtoreg, memwrite, pcsrc, alusrc, regdst, regwrite, jump, 
	output	[2:0]	alucontrol,
	output 	jalSel, jumpreg,
	output	[1:0] 	regWriteSel,
	output 	writeHiLoreg );
	

	wire	[1:0]	aluop;
	wire			branch;

	maindec	md(op, memtoreg, memwrite, branch, alusrc, regdst, regwrite, jump, aluop, jalSel); // editting
	aludec	ad(funct, aluop, alucontrol, jumpreg, regWriteSel, writeHiLoreg); // editting

	assign pcsrc = branch & zero;
endmodule

// Data Path (excluding the instruction and data memories)
module datapath(
	input			clk, reset, memtoreg, pcsrc, alusrc, regdst, regwrite, memwrite, jump, jumpreg, jalSel,
	input	[1:0]	regWriteSel,
	input 		writeHiLoreg,
	input	[2:0]	alucontrol,
	output			zero,
	output	[31:0]	pc,
	input	[31:0]	instr,	
	input	[31:0]	readdata,
	input	[ 4:0]	dispSel,
	output	[31:0]	dispDat,
	output  [31:0]  instr_ID,
	output  [31:0]  aluout_MEM,
	output  [31:0]  writedata_MEM,
	output 			memwrite_MEM );


	wire [4:0]  writereg;
	wire [4:0]  dstjalout;
	wire [31:0] pcnext, pcnextbr, pcnextjr, pcplus4, pcbranch, signimm,
					signimmsh, srca, srcb, result, regwritemuxout, jaloutmux, aluoutExt;
	
	// Pipeline signals
	wire	[31:0]	aluout, writedata;
	// Pipeline_IF_ID
	wire [31:0]  pcplus4_ID;
	// Pipeline_ID_EX
	wire [4:0] instr_20_16_EX, instr_15_11_EX;
	wire [31:0] signimm_EX;
	// Pipeline_EX_MEM	
	wire jalSel_EX, regwrite_EX, memwrite_EX, memtoreg_EX, writeHiLoreg_EX, regdst_EX, alusrc_EX;
	wire [2:0] alucontrol_EX;
	wire [1:0] regWriteSel_EX;
	wire [31:0] srca_EX, aluout_EX, aluoutExt_MEM, writedata_EX;
	wire [31:0] pcplus4_EX;
	// Pipeline_MEM_WB
	wire jalSel_MEM, regwrite_MEM, memtoreg_MEM, writeHiLoreg_MEM;
	wire [1:0] regWriteSel_MEM;
	wire [4:0] writereg_MEM;
	wire [31:0] pcplus4_MEM;
	wire [31:0] readhi_MEM, readlo_MEM;
	wire jalSel_WB, regwrite_WB, memtoreg_WB;
	wire [1:0] regWriteSel_WB;
	wire [31:0] readdata_WB, aluout_WB, readhi_WB, readlo_WB;
	wire [4:0] writereg_WB;
	wire [31:0] pcplus4_WB;
	
	// next PC logic
	flopr #(32) pcreg(clk, reset, pcnext, pc);
	adder       pcadd1(pc, 32'b100, pcplus4);
	sl2         immsh(signimm, signimmsh);
	adder       pcadd2(pcplus4_ID, signimmsh, pcbranch);
	
	mux2 #(32)  pcbrmux(pcnextjr, pcbranch, pcsrc, pcnextbr);
	mux2 #(32)  pcmux(pcnextbr, {pcplus4[31:28], instr_ID[25:0], 2'b00}, jump, pcnext);
	
	// editting
	mux4 #(32)  regwritemux(result, readhi_WB, readlo_WB, 0, regWriteSel_WB, regwritemuxout);  
	mux2 #(32)	jalmux(regwritemuxout, pcplus4_WB, jalSel_WB, jaloutmux); // editting
	mux2 #(32)  pcjrmux(pcplus4, srca, jumpreg, pcnextjr);
	mux2 #(5)	dstjalmux(writereg_WB, 5'b11111, jalSel_WB, dstjalout);
	

	
	
	// hi, lo regs
	smallReg		hi(clk, writeHiLoreg_MEM, aluoutExt_MEM, readhi_MEM);	// done
	smallReg		lo(clk, writeHiLoreg_MEM, aluout_MEM, readlo_MEM);	// done
	// end editting
	
	// register file logic
	regfile		rf(clk, regwrite_WB, instr_ID[25:21], instr_ID[20:16], dstjalout, jaloutmux, srca, writedata, dispSel, dispDat); // editting
	mux2 #(5)	wrmux(instr_20_16_EX, instr_15_11_EX, regdst_EX, writereg);
	mux2 #(32)	resmux(aluout_WB, readdata_WB, memtoreg_WB, result);
	signext		se(instr_ID[15:0], signimm);

	// ALU logic
	mux2 #(32)	srcbmux(writedata_EX, signimm_EX, alusrc_EX, srcb);
	alu			alu(srca_EX, srcb, alucontrol_EX, aluout, aluoutExt, zero);
	
	
	
	
	
	pipelineReg_IF_ID pipeline_IF_ID( clk, instr, pcplus4, instr_ID, pcplus4_ID );
	
	
	
	pipelineReg_ID_EX pipeline_ID_EX( clk, jalSel, regwrite, regdst, alusrc, memwrite, memtoreg, alucontrol, regWriteSel, writeHiLoreg,
									  srca, writedata, instr_ID[20:16], instr_ID[15:11], signimm, pcplus4_ID,
									  jalSel_EX, regwrite_EX, regdst_EX, alusrc_EX, memwrite_EX, memtoreg_EX, alucontrol_EX, regWriteSel_EX, writeHiLoreg_EX, 
									  srca_EX, writedata_EX, instr_20_16_EX, instr_15_11_EX, signimm_EX, pcplus4_EX);
	
	
	
	pipelineReg_EX_MEM pipeline_EX_MEM(clk, jalSel_EX, regwrite_EX, memwrite_EX, memtoreg_EX, writeHiLoreg_EX, regWriteSel_EX,
									   aluout, aluoutExt, writedata_EX, writereg, pcplus4_EX,
									   jalSel_MEM, regwrite_MEM, memwrite_MEM, memtoreg_MEM, writeHiLoreg_MEM, regWriteSel_MEM,
									   aluout_MEM, aluoutExt_MEM, writedata_MEM, writereg_MEM, pcplus4_MEM);
	 // Not sure whats up with the HI LO regs inputs. Both of them are getting aluout_MEM? Thats how i have it currently, fix!
	 
	
	
	pipelineReg_MEM_WB pipeline_MEM_WB( clk, jalSel_MEM, regwrite_MEM, memtoreg_MEM, regWriteSel_MEM,
										readdata, aluout_MEM, readhi_MEM, readlo_MEM, writereg_MEM, pcplus4_MEM,
										jalSel_WB, regwrite_WB, memtoreg_WB, regWriteSel_WB, readdata_WB, aluout_WB, readhi_WB, readlo_WB, writereg_WB, pcplus4_WB
										);
								
	// Stuff needs fixing: LO Register, output that comes from ALU and has to go through pipeline
	// Also have not done anything to the MUX-es on the left-most side of the vizio diagram
endmodule

// The MIPS (excluding the instruction and data memories)
module mips(
	input        	clk, reset,
	output	[31:0]	pc,
	input 	[31:0]	instr,
	output			memwrite_MEM,
	output	[31:0]	aluout_MEM, writedata_MEM,
	input 	[31:0]	readdata,
	input	[ 4:0]	dispSel,
	output	[31:0]	dispDat );

	// deleted wire "branch" - not used
	wire 			memtoreg, pcsrc, zero, alusrc, regdst, regwrite, memwrite, jump, jumpreg, jalSel; // editting
	wire	[2:0] 	alucontrol;
	wire	[1:0] 	regWriteSel;
	wire			writeHiLoreg;
	wire	[31:0]  instr_ID;
	//wire	[31:0]	aluout_MEM;
	//wire    [31:0]  writedata_MEM;

	controller c(instr_ID[31:26], instr_ID[5:0], zero,
				memtoreg, memwrite, pcsrc,
				alusrc, regdst, regwrite, jump,
				alucontrol, jalSel, jumpreg, regWriteSel, writeHiLoreg); 
				
	datapath dp(clk, reset, memtoreg, pcsrc,
				alusrc, regdst, regwrite, memwrite, jump, jumpreg, jalSel, regWriteSel, writeHiLoreg,
				alucontrol, zero, pc, instr, 
				readdata, dispSel, dispDat, 
				instr_ID, aluout_MEM, writedata_MEM, memwrite_MEM);
endmodule

// Instruction Memory
module imem (
	input	[ 6:0]	a,
	output 	[31:0]	dOut );
	
	reg		[31:0]	rom[0:127];
	
	//initialize rom from memfile_s.dat
	initial 
		begin
		
		$readmemh("C:/Users/Greg/Documents/CMPE140/final lab/memfile_s.dat", rom);
		end
	//simple rom
    assign dOut = rom[a];
endmodule

// Data Memory
module dmem (
	input			clk,
	input			we,
	input	[31:0]	addr,
	input	[31:0]	dIn,
	output 	[31:0]	dOut );
	
	reg		[31:0]	ram[511:0];
	integer			n;
	
	//initialize ram to all FFs
	initial 
		for (n=0; n<512; n=n+1)
			ram[n] = 8'hFF;
		
	assign dOut = ram[addr[31:2]];
				
	always @(posedge clk)
		if (we) 
			ram[addr[31:2]] = dIn; 
endmodule

public class code 
{
	//translate hack to binary for comp
	public String comp(String comphack) {
        String compbinary = null;
        if(comphack == null) 
		{ 
			return null; 
		}
        else if(comphack.equals("0")) 
		{ 
			compbinary = "0101010"; 
		}
        else if(comphack.equals("1")) 
		{ 
			compbinary = "0111111"; 
		}
        else if(comphack.equals("-1")) 
		{ 
			compbinary = "0111010";
		}
        else if(comphack.equals("D")) 
		{ 
			compbinary = "0001100";
		}
        else if(comphack.equals("A")) 
		{
			compbinary = "0110000"; 
		}
        else if(comphack.equals("!D")) 
		{ 
			compbinary = "0001101";
		}
        else if(comphack.equals("!A")) 
		{
			compbinary = "0110001";
		}
        else if(comphack.equals("-D")) 
		{
			compbinary = "0001111";
		}
        else if(comphack.equals("-A")) 
		{
			compbinary = "0110011"; 
		}
        else if(comphack.equals("D+1")) 
		{
			compbinary = "0011111";
		}
        else if(comphack.equals("A+1")) 
		{ 
			compbinary = "0110111";
		}
        else if(comphack.equals("D-1")) 
		{
			compbinary = "0001110";
		}
        else if(comphack.equals("A-1")) 
		{
			compbinary = "0110010";
		}
        else if(comphack.equals("D+A")) 
		{
			compbinary = "0000010";
		}
        else if(comphack.equals("D-A")) 
		{
			compbinary = "0010011";
		}
        else if(comphack.equals("A-D")) 
		{
			compbinary = "0000111";
		}
        else if(comphack.equals("D&A")) 
		{
			compbinary = "0000000";
		}
        else if(comphack.equals("D|A")) 
		{
			compbinary = "0010101";
		}
        else if(comphack.equals("M")) 
		{
			compbinary = "1110000";
		}
        else if(comphack.equals("!M")) 
		{
			compbinary = "1110001";
		}
        else if(comphack.equals("-M")) 
		{
			compbinary = "1110011";
		}
        else if(comphack.equals("M+1")) 
		{
			compbinary = "1110111";
		}
        else if(comphack.equals("M-1")) 
		{
			compbinary = "1110010";
		}
        else if(comphack.equals("D+M")) 
		{
			compbinary = "1000010";
		}
        else if(comphack.equals("D-M")) 
		{
			compbinary = "1010011";
		}
        else if(comphack.equals("M-D")) 
		{
			compbinary = "1000111";
		}
        else if(comphack.equals("D&M")) 
		{
			compbinary = "1000000";
		}
        else if(comphack.equals("D|M")) 
		{
			compbinary = "1010101";
		}
        else{ }
        return compbinary;
    }
	//translate hack to binary for dest
	public String dest(String desthack) {
        String destbinary = null;
        if(desthack == null) 
		{
			destbinary = "000";
		}
        else if(desthack.equals("M")) 
		{
			destbinary = "001";
		}
        else if(desthack.equals("D")) 
		{
			destbinary = "010";
		}
        else if(desthack.equals("MD")) 
		{
			destbinary = "011";
		}
        else if(desthack.equals("A")) 
		{
			destbinary = "100";
		}
        else if(desthack.equals("AM")) 
		{
			destbinary = "101";
		}
        else if(desthack.equals("AD")) 
		{
			destbinary = "110";
		}
        else if(desthack.equals("AMD")) 
		{
			destbinary = "111";
		}
        else{ }
        return destbinary;
    }
	//translate hack to binary for jump
	public String jump(String jumphack) {
        String jumpbinary;
        if(jumphack == null) 
		{
			jumpbinary = "000";
		}
        else if(jumphack.equals("JGT")) 
		{
			jumpbinary = "001";
		}
        else if(jumphack.equals("JEQ")) 
		{
			jumpbinary = "010";
		}
        else if(jumphack.equals("JGE")) 
		{
			jumpbinary = "011";
		}
        else if(jumphack.equals("JLT")) 
		{
			jumpbinary = "100";
		}
        else if(jumphack.equals("JNE")) 
		{
			jumpbinary = "101";
		}
        else if(jumphack.equals("JLE")) 
		{
			jumpbinary = "110";
		}
        else if(jumphack.equals("JMP")) 
		{
			jumpbinary = "111";
		}
        else 
		{
			jumpbinary = "000";
		}
        return jumpbinary;
    }
}
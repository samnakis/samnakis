import java.lang.StringBuilder;

public class assembler {
    static int A_COMMAND = 0;
    static int C_COMMAND = 1;
    static int L_COMMAND = 2;
    static int VAR = 16;

	public static void main(String[] args) 
	{
        String fileName = args[0];
        parser parser = new parser(fileName);
        code codes = new code();
        symbols sym = new symbols();

        firstPass(parser, sym);

        parser = new parser(fileName);
        String outName = fileName.split("[.]")[0];
        Out output = new Out(outName);
        secondPass(parser, codes, sym, output);

        output.close();
    }
	//see if L command or not
    public static void firstPass(parser parser, symbols sym) 
	{
        int counter = -1;
        String symbol = null;
        while(parser.hasMoreCommands())
		{
			parser.advance();
			if(parser.commandType() == L_COMMAND) 
			{
				symbol = parser.symbol();
				sym.addEntry(symbol, counter + 1);
			} 
			else
			{ 
				counter++; 
			}
		}
    }

    public static void secondPass(parser parser, code codes, symbol sym, Out output)
	{
	//get hack and translate into binary for a and c commands
        while(parser.hasMoreCommands()) 
		{
            parser.advance();
            if(parser.commandType() == A_COMMAND) 
			{
                String symbola = parser.symbol();
                String comma = generateACommand(symbola, sym);
                output.println(comma);
            } 
			else if(parser.commandType() == C_COMMAND) 
			{
                String dest = parser.dest();
                String comp = parser.comp();
                String jump = parser.jump();
                String commc = generateCCommand(dest, comp, jump, codes);
                output.println(commc);
            }
        }
    }
//a commnads
    private static String generateACommand(String symbol, symbol sym)
	{
        String code = null;
        int address;
        if(isNumeric(symbol)) 
		{
            address = Integer.parseInt(symbol);
        } 
		else 
		{
            if(sym.contains(symbol)) 
			{
                address = sym.getAddress(symbol);
            } 
			else 
			{
                address = VAR++;
                sym.addEntry(symbol, address);
            }
        }
        String binary = Integer.toBinaryString(address);
        code = changeLength(binary, 16);
        return code;
    }

    private static boolean isNumeric(String str) 
	{
        if(str.length() == 0) 
		{ 
			return false;
		}
        for(char c : str.toCharArray())
        {
            if(!Character.isDigit(c)) 
			{
				return false;
			}
        }
        return true;
    }

    private static String changeLength(String str, int number) 
	{
        int zero = number - str.length();
        StringBuilder zeros = new StringBuilder();
        for(int i = zero; i > 0; i--)
		{
            zeros.append("0");
		}
        zeros.append(str);
        return zeros.toString();
    }
//c commands
    public static String generateCCommand(String dest, String comp, String jump, code codes) 
	{
        StringBuilder code = new StringBuilder();
        code.append("111");
        String compCode = codes.comp(comp);
        code.append(compCode);
        String destCode = codes.dest(dest);
        code.append(destCode);
        String jumpCode = codes.jump(jump);
        code.append(jumpCode);
        return code.toString();
    }

   
}
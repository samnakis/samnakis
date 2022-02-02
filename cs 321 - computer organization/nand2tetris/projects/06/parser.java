public class parser {
    static int A_COMMAND = 0;
    static int C_COMMAND = 1;
    static int L_COMMAND = 2;

    private In file;
    private String currentCommand;

	//find file name
    public parser(String filename) 
	{
        file = new In(filename);
    }
	//check for more lines
	public boolean hasMoreCommands() 
	{
        if(file.hasNextLine()) 
		{
            return true;
        } 
		else
		{
            file.close();
            return false;
        }
    }
	public void advance() 
	{
		//continue to next line and get rid of spaces and comments
        String line;
        do{line = file.readLine().trim();} 
		while(line.equals("") || line.substring(0,2).equals("//"));
		{
			String[] parts = line.split("//");
		}
        currentCommand = parts[0];
        currentCommand = currentCommand.replace(" ", "");
    }
	
	//check type of command
	public int commandType() 
	{
        char iValue = currentCommand.charAt(0);
        if(iValue == '@') 
		{
			return A_COMMAND; 
		}
        else if(iValue == '(') 
		{ 
			return L_COMMAND; 
		}
        else
		{ 
			return C_COMMAND; 
		}
    }
	
	//c-command values
	//comp
	public String comp() 
	{
        String comp = null;
        if(this.commandType() == C_COMMAND) 
		{
            if(currentCommand.indexOf("=") != -1) 
			{//get commande right of equals sign
                comp = currentCommand.split("=")[1];
            } 
			else if(currentCommand.indexOf(";") != -1) 
			{
                comp = currentCommand.split(";")[0];
            } 
			else { }
        }
        return comp;
    }
	//dest
	 public String dest() 
	 {
        String dest = null;
        if(this.commandType() == C_COMMAND && currentCommand.indexOf("=") != -1)
        {    
			dest = currentCommand.split("=")[0];
		}
        return dest;
    }
	//jump
	 public String jump() 
	 {
        String jump = null;
        if(this.commandType() == C_COMMAND) 
		{
            if(currentCommand.indexOf(";") != -1) 
			{
                jump = currentCommand.split(";")[1];
            } 
			else { }
        }
        return jump;
    }
	//symbols
	 public String symbol() 
	 {
        String symbol = null;
        if(this.commandType() == A_COMMAND ) 
		{
            symbol = currentCommand.substring(1, currentCommand.length());
        } 
		else if(this.commandType() == L_COMMAND) 
		{
            symbol = currentCommand.substring(1, currentCommand.length() - 1);
        }
        else { }
        return symbol;
    }
}
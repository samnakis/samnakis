import java.io.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;


class JTT3 extends JFrame implements ActionListener
{
    //closes program
    class dad extends WindowAdapter
    {
        public void windowClosing(WindowEvent e)
        {
            System.out.println("Hope you had fun!");
            System.exit(0);
        }
    }

    //information for building circles
    class Fish
    {
        Color color;
        int size;
        int x,y;
        public int status;

        public Fish(int x, int y, Color c, int s) 
        { this.x=x; this.y=y; color=c; size=s; }


        public void setMoveColor()
        {
            if (status==0)
                color=Color.black;
            if (status==1)
                color=new Color(229,184,201);
            if (status==2)
                color=new Color(176,224,242);
        }
		
        public void draw(Graphics g)
        {
            setMoveColor();
            g.setColor(color);
            g.fillOval(x,y, size,size);
        }
    }
    //starts the game
    public int stage=0;

    //helper functions
    class Ocean extends JPanel
    {
        Fish [] school;

        //creates array of circles
        public Ocean()
        {
            school=new Fish[10];
            setSize(1000,600);
            school[0]=new Fish(50,50, Color.yellow, 130);
            school[1]=new Fish(50,50, Color.yellow, 130);
            school[2]=new Fish(450,50, Color.yellow, 130);
            school[3]=new Fish(850,50, Color.yellow, 130);
            school[4]=new Fish(250,300, Color.yellow, 130);
            school[5]=new Fish(450,300, Color.yellow, 130);
            school[6]=new Fish(650,300, Color.yellow, 130);
            school[7]=new Fish(50,550, Color.yellow, 130);
            school[8]=new Fish(450,550, Color.yellow, 130);
            school[9]=new Fish(850,550, Color.yellow, 130);

            for(int i=0; i<school.length; i++)
                school[i].setMoveColor();
        }

        //instructions for player to move
        public void playermove(int i) 
        {
            if (school[i].status==0)
            {
                school[i].status=1;
                school[i].setMoveColor();
            }
            else if (school[i].status==1 || school[i].status==2)
            {
                input.setText("Invalid choice. Thanks for the free move!!");
            }   
        }

        //instructions for computer to move
        public void computermove(int i) 
        { 
            school[i].status=2;
            school[i].setMoveColor(); 
        }

        //tells if board is full
        public boolean boardfull()
        {
            int boardcount=0;

            for (int i=1; i<school.length; i++)
            {
                if(school[i].status==1 || school[i].status==2)
                    boardcount++;
            }
            if (boardcount==9)
            {
                stage=5;
                return true;
            }
            else
                return false;
        }

        //artificial intelligence
        public void AI()
        {
            int choice=0;
			
			//computer making moves to win
            if(school[1].status==2 && school[2].status==2 && school[3].status==0)
                choice=3;
            else if(school[1].status==2 && school[3].status==2 && school[2].status==0)
                choice=2;
            else if(school[2].status==2 && school[3].status==2 && school[1].status==0)
                choice=1;

            else if(school[1].status==2 && school[4].status==2 && school[8].status==0)
                choice=8;
            else if(school[1].status==2 && school[8].status==2 && school[4].status==0)
                choice=4;
            else if(school[4].status==2 && school[8].status==2 && school[1].status==0)
                choice=1;

            else if(school[1].status==2 && school[5].status==2 && school[9].status==0)
                choice=9;
            else if(school[1].status==2 && school[9].status==2 && school[5].status==0)
                choice=5;
            else if(school[5].status==2 && school[9].status==2 && school[1].status==0)
                choice=1;

            else if(school[2].status==2 && school[4].status==2 && school[7].status==0)
                choice=7;
            else if(school[2].status==2 && school[7].status==2 && school[4].status==0)
                choice=4;
            else if(school[4].status==2 && school[7].status==2 && school[2].status==0)
                choice=2;

            else if(school[2].status==2 && school[6].status==2 && school[9].status==0)
                choice=9;
            else if(school[2].status==2 && school[9].status==2 && school[6].status==0)
                choice=6;
            else if(school[6].status==2 && school[9].status==2 && school[2].status==0)
                choice=2;

            else if(school[3].status==2 && school[5].status==2 && school[7].status==0)
                choice=7;
            else if(school[3].status==2 && school[7].status==2 && school[5].status==0)
                choice=5;
            else if(school[5].status==2 && school[7].status==2 && school[3].status==0)
                choice=3;
            
            else if(school[3].status==2 && school[6].status==2 && school[8].status==0)
                choice=8;
            else if(school[3].status==2 && school[8].status==2 && school[6].status==0)
                choice=6;
            else if(school[6].status==2 && school[8].status==2 && school[3].status==0)
                choice=3;

            else if(school[4].status==2 && school[5].status==2 && school[6].status==0)
                choice=6;
            else if(school[4].status==2 && school[6].status==2 && school[5].status==0)
                choice=5;
            else if(school[5].status==2 && school[6].status==2 && school[4].status==0)
                choice=4;

            else if(school[7].status==2 && school[8].status==2 && school[9].status==0)
                choice=9;
            else if(school[7].status==2 && school[9].status==2 && school[8].status==0)
                choice=8;
            else if(school[8].status==2 && school[9].status==2 && school[7].status==0)
                choice=7;


			//computer blocking player win moves
            else if(school[1].status==1 && school[2].status==1 && school[3].status==0)
                choice=3;
            else if(school[1].status==1 && school[3].status==1 && school[2].status==0)
                choice=2;
            else if(school[2].status==1 && school[3].status==1 && school[1].status==0)
                choice=1;

            else if(school[1].status==1 && school[4].status==1 && school[8].status==0)
                choice=8;
            else if(school[1].status==1 && school[8].status==1 && school[4].status==0)
                choice=4;
            else if(school[4].status==1 && school[8].status==1 && school[1].status==0)
                choice=1;

            else if(school[1].status==1 && school[5].status==1 && school[9].status==0)
                choice=9;
            else if(school[1].status==1 && school[9].status==1 && school[5].status==0)
                choice=5;
            else if(school[5].status==1 && school[9].status==1 && school[1].status==0)
                choice=1;

            else if(school[2].status==1 && school[4].status==1 && school[7].status==0)
                choice=7;
            else if(school[2].status==1 && school[7].status==1 && school[4].status==0)
                choice=4;
            else if(school[4].status==1 && school[7].status==1 && school[2].status==0)
                choice=2;

            else if(school[2].status==1 && school[6].status==1 && school[9].status==0)
                choice=9;
            else if(school[2].status==1 && school[9].status==1 && school[6].status==0)
                choice=6;
            else if(school[6].status==1 && school[9].status==1 && school[2].status==0)
                choice=2;

            else if(school[3].status==1 && school[5].status==1 && school[7].status==0)
                choice=7;
            else if(school[3].status==1 && school[7].status==1 && school[5].status==0)
                choice=5;
            else if(school[5].status==1 && school[7].status==1 && school[3].status==0)
                choice=3;
                
            else if(school[3].status==1 && school[6].status==1 && school[8].status==0)
                choice=8;
            else if(school[3].status==1 && school[8].status==1 && school[6].status==0)
                choice=6;
            else if(school[6].status==1 && school[8].status==1 && school[3].status==0)
                choice=3;

            else if(school[4].status==1 && school[5].status==1 && school[6].status==0)
                choice=6;
            else if(school[4].status==1 && school[6].status==1 && school[5].status==0)
                choice=5;
            else if(school[5].status==1 && school[6].status==1 && school[4].status==0)
                choice=4;

            else if(school[7].status==1 && school[8].status==1 && school[9].status==0)
                choice=9;
            else if(school[7].status==1 && school[9].status==1 && school[8].status==0)
                choice=8;
            else if(school[8].status==1 && school[9].status==1 && school[7].status==0)
                choice=7;
		
			
			//computer making next move based off of what it already has and isn't able 			to win in next move or block player win
            else if(school[1].status==2 && school[2].status==0 && school[3].status==0)
                choice=2;
            else if(school[1].status==2 && school[4].status==0 && school[8].status==0)
                choice=4;
            else if(school[1].status==2 && school[5].status==0 && school[9].status==0)
                choice=5;
			
            else if(school[2].status==2 && school[1].status==0 && school[3].status==0)
                choice=1;
            else if(school[2].status==2 && school[3].status==0 && school[1].status==0)
                choice=3;
            else if(school[2].status==2 && school[4].status==0 && school[7].status==0)
                choice=4;
            else if(school[2].status==2 && school[6].status==0 && school[9].status==0)
                choice=6;
			
            else if(school[3].status==2 && school[2].status==0 && school[1].status==0)
                choice=2;
            else if(school[3].status==2 && school[5].status==0 && school[7].status==0)
                choice=5;
            else if(school[3].status==2 && school[6].status==0 && school[8].status==0)
                choice=6;
			
            else if(school[4].status==2 && school[1].status==0 && school[8].status==0)
                choice=1;
            else if(school[4].status==2 && school[2].status==0 && school[7].status==0)
                choice=2;
            else if(school[4].status==2 && school[5].status==0 && school[6].status==0)
                choice=5;
            else if(school[4].status==2 && school[7].status==0 && school[2].status==0)
                choice=7;
            else if(school[4].status==2 && school[8].status==0 && school[1].status==0)
                choice=8;
			
            else if(school[5].status==2 && school[1].status==0 && school[9].status==0)
                choice=1;
            else if(school[5].status==2 && school[3].status==0 && school[7].status==0)
                choice=3;
            else if(school[5].status==2 && school[7].status==0 && school[3].status==0)
                choice=7;
            else if(school[5].status==2 && school[9].status==0 && school[1].status==0)
                choice=9;
			
            else if(school[6].status==2 && school[2].status==0 && school[9].status==0)
                choice=2;
            else if(school[6].status==2 && school[3].status==0 && school[8].status==0)
                choice=3;
            else if(school[6].status==2 && school[5].status==0 && school[4].status==0)
                choice=5;
            else if(school[6].status==2 && school[8].status==0 && school[3].status==0)
                choice=8;
            else if(school[6].status==2 && school[9].status==0 && school[2].status==0)
                choice=9;
			
            else if(school[7].status==2 && school[4].status==0 && school[2].status==0)
                choice=4;
            else if(school[7].status==2 && school[5].status==0 && school[3].status==0)
                choice=5;
            else if(school[7].status==2 && school[8].status==0 && school[9].status==0)
                choice=8;
			
            else if(school[8].status==2 && school[4].status==0 && school[1].status==0)
                choice=4;
            else if(school[8].status==2 && school[6].status==0 && school[3].status==0)
                choice=6;
            else if(school[8].status==2 && school[7].status==0 && school[9].status==0)
                choice=7;
            else if(school[8].status==2 && school[9].status==0 && school[7].status==0)
                choice=9;
			
            else if(school[9].status==2 && school[5].status==0 && school[1].status==0)
                choice=5;
            else if(school[9].status==2 && school[6].status==0 && school[2].status==0)
                choice=6;
            else if(school[9].status==2 && school[8].status==0 && school[7].status==0)
                choice=8;
			
			
			//computer making next move based off of what the player already has and 			the player or computer isn't able to win in next turn
            else if(school[1].status==1 && school[2].status==0)
                choice=2;
            else if(school[1].status==1 && school[4].status==0)
                choice=4;
            else if(school[1].status==1 && school[5].status==0)
                choice=5;
			
            else if(school[2].status==1 && school[1].status==0)
                choice=1;
            else if(school[2].status==1 && school[3].status==0)
                choice=3;
            else if(school[2].status==1 && school[4].status==0)
                choice=4;
            else if(school[2].status==1 && school[6].status==0)
                choice=6;
			
            else if(school[3].status==1 && school[2].status==0)
                choice=2;
            else if(school[3].status==1 && school[5].status==0)
                choice=5;
            else if(school[3].status==1 && school[6].status==0)
                choice=6;
			
            else if(school[4].status==1 && school[1].status==0)
                choice=1;
            else if(school[4].status==1 && school[2].status==0)
                choice=2;
            else if(school[4].status==1 && school[5].status==0)
                choice=5;
            else if(school[4].status==1 && school[7].status==0)
                choice=7;
            else if(school[4].status==1 && school[8].status==0)
                choice=8;
			
            else if(school[5].status==1 && school[1].status==0)
                choice=1;
            else if(school[5].status==1 && school[3].status==0)
                choice=3;
            else if(school[5].status==1 && school[7].status==0)
                choice=7;
            else if(school[5].status==1 && school[9].status==0)
                choice=9;
			
            else if(school[6].status==1 && school[2].status==0)
                choice=2;
            else if(school[6].status==1 && school[3].status==0)
                choice=3;
            else if(school[6].status==1 && school[5].status==0)
                choice=5;
            else if(school[6].status==1 && school[8].status==0)
                choice=8;
            else if(school[6].status==1 && school[9].status==0)
                choice=9;
			
            else if(school[7].status==1 && school[4].status==0)
                choice=4;
            else if(school[7].status==1 && school[5].status==0)
                choice=5;
            else if(school[7].status==1 && school[8].status==0)
                choice=8;
			
            else if(school[8].status==1 && school[4].status==0)
                choice=4;
            else if(school[8].status==1 && school[6].status==0)
                choice=6;
            else if(school[8].status==1 && school[7].status==0)
                choice=7;
            else if(school[8].status==1 && school[9].status==0)
                choice=9;
			
            else if(school[9].status==1 && school[5].status==0)
                choice=5;
            else if(school[9].status==1 && school[6].status==0)
                choice=6;
            else if(school[9].status==1 && school[8].status==0)
                choice=8;
			
			//picking random if nothing else is an effective move
            else
            {
                int go=0;
                while(go==0)
                {
                    choice=(int)(1+9*Math.random());
                    if (school[choice].status==0)
                        go++;
                    else
                        go=0;
                }
            }
            pacific.computermove(choice);
        }

        //check to see if someone wins
        public boolean win()
        {
            if ((school[1].status==1 && school[2].status==1 && school[3].status==1) ||
            (school[1].status==1 && school[4].status==1 && school[8].status==1) ||
            (school[1].status==1 && school[5].status==1 && school[9].status==1) ||
            (school[2].status==1 && school[4].status==1 && school[7].status==1) ||
            (school[2].status==1 && school[6].status==1 && school[9].status==1) ||
            (school[3].status==1 && school[5].status==1 && school[7].status==1) ||
            (school[3].status==1 && school[6].status==1 && school[8].status==1) ||
            (school[4].status==1 && school[5].status==1 && school[6].status==1) ||
            (school[7].status==1 && school[8].status==1 && school[9].status==1))
            {
                stage=3;
                return true;
            }
            else if((school[1].status==2 && school[2].status==2 && school[3].status==2) ||
            (school[1].status==2 && school[4].status==2 && school[8].status==2) ||
            (school[1].status==2 && school[5].status==2 && school[9].status==2) ||
            (school[2].status==2 && school[4].status==2 && school[7].status==2) ||
            (school[2].status==2 && school[6].status==2 && school[9].status==2) ||
            (school[3].status==2 && school[5].status==2 && school[7].status==2) ||
            (school[3].status==2 && school[6].status==2 && school[8].status==2) ||
            (school[4].status==2 && school[5].status==2 && school[6].status==2) ||
            (school[7].status==2 && school[8].status==2 && school[9].status==2))
            {
                stage=4;
                return true;
            }
            else if(pacific.boardfull()==true)
            {
                stage=5;
                return true;
            }
            else
                return false;
        }
        
        //resets the board
        public void reset()
        {
            for(int i=1; i<school.length; i++)
            {
                school[i].status=0;
            }
            pacific.repaint();
            stage=0;

        } 

        //draws the lines and numbers
        public void paintComponent(Graphics g)
        {
            g.setColor(Color.black);
            g.drawLine(115,115, 915,115);
            g.drawLine(315,365, 715,365);
            g.drawLine(115,615, 915,615);

            g.drawLine(115,115, 915,615);
            g.drawLine(115,615, 915,115);

            g.drawLine(115,115, 515,615);
            g.drawLine(515,115, 915,615);

            g.drawLine(115,615, 515,115);
            g.drawLine(515,615, 915,115);
			
            for(int i=0; i<school.length; i++)
                school[i].draw(g);

            Font font=new Font("SansSerif", Font.BOLD, 50);
            g.setFont(font);
            g.setColor(Color.white);
       
            g.drawString("1", 98,135);
            g.drawString("2", 498,135);
            g.drawString("3", 898,135);
            g.drawString("4", 298,385);
            g.drawString("5", 498,385);
            g.drawString("6", 698,385);
            g.drawString("7", 98,635);
            g.drawString("8", 498,635);
            g.drawString("9", 898,635);  
        }
    }

    JTextField input;
    JButton move;
    int count;
    Ocean pacific;
    
    //plays the game
    public void actionPerformed(ActionEvent e)
    {
        if(stage==0)
        {
            if(e.getSource()==move)
            {
                if(input.getText().charAt(0)=='C')
                    stage=2;
                
                else
                    stage=1;
            }
        }

        if(stage==1)
        {
            if(e.getSource()==move)
            {
                String x=input.getText();
                int i=Integer.parseInt(x);
                pacific.playermove(i);
                pacific.win();

                if(pacific.boardfull()==false && pacific.win()==false)
                {
                    pacific.AI();
                    pacific.win();
                }
            }
        else
            count++;
        }

        if(stage==2)
        {
            pacific.AI();
            stage=1;
        }

        if(stage==3)
        {
            input.setText("Player wins! Do you want to play again? Y or N");
            stage=6;
        }

        if(stage==4)
        {
            input.setText("Computer wins! Do you want to play again? Y or N");
            stage=6;
        }

        if(stage==5)
        {
            input.setText("Tie! Do you want to play again? Y or N");
            stage=6;
        }

        if(stage==6)
        {
            if(e.getSource()==move)
            {
                if(input.getText().charAt(0)=='Y')   
                {
                    pacific.reset();
                    input.setText("Who goes first? Choose (C)omputer or enter a number to begin.");
                }
                else if (input.getText().charAt(0)=='N')
                {
                    System.out.println("Hope you had fun!");
                    System.exit(0);
                }
            }
        }

        pacific.repaint();
    }

    //gui stuff
    public JTT3()
    {
        setTitle("Jerry-Tac-Toe");
        setSize(1100,800);
        addWindowListener(new dad());

        move=new JButton("   Make Move   ");
        input=new JTextField("");
        input.setText("Who goes first? Choose (C)omputer or enter a number to begin.");
        pacific=new Ocean();

        move.addActionListener(this);

        // put stuff in the window
        Container glass=getContentPane();
        glass.setLayout( new BorderLayout() ); // layout manager

        JPanel bottom=new JPanel();
        bottom.setLayout(new BorderLayout());
        bottom.add(input,"Center");
        bottom.add(move,"East");

        glass.add(pacific,"Center");
        glass.add(bottom,"South");
        glass.add(new JPanel(),"East");
        glass.add(new JPanel(),"West");

        setVisible(true);
    }

    public static void main(String [] args)
    {
        JTT3 gelatinousCube=new JTT3();
    }
}
public class MyDate implements DateInterface
{
	int day;
	int month;
	int year;
	int week;
	
	//constructor
	public MyDate(int m, int d, int y, int dow)
	{
		day=d;
		month=m;
		year=y;
		week=dow;
	}
	
	public MyDate() { }
	public int getDay() { return day; }
	public int getDow() { return week; }
	public int getMonth() { return month; }
	public int getYear() { return year; }
	
	//sets date
	public void set(int m, int d, int y, int dow)
	{
		month=m;
		day=d;
		year=y;
		week=dow;
	}
	
	public void tomorrow()
	{
		//31 day months
		if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
		{
			day++;
			if(day>31)
			{
				day=1;
				month++;
				
				if(month>12)
				{
					month=1;
					year++;
				}
			}
			
			week++;
			if(week>6)
			{
				week=0;
			}
		}
		
		//30 day months
		else if(month==4 || month==6 || month==9 || month==11)
		{
			day++;
			if(day>30)
			{
				day=1;
				month++;
			}
			
			week++;
			if(week>6)
			{
				week=0;
			}
		}
		
		//february
		else
		{
			day++;
			if(day>28)
			{
				day=1;
				month++;
			}
			
			week++;
			if(week>6)
			{
				week=0;
			}
		}
	}
	
	//returns date as a string
	public String toString()
	{
		//naming days of the week
		String [] dow={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
		
		//naming months
		String [] mon={"January","February","March","April","May","June","July","August",
		"September","October","November","December"};
		
		return dow[week]+", "+mon[month-1]+" "+day+", "+year;
	}
	
	public void today() { }
	public void yesterday() { }
}
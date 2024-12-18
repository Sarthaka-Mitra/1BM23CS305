class Lab implements Runnable {
	Thread t;
	String name;
	Lab(String th){
		name = th;
		t = new Thread(this, th);
		System.out.println("Child thread: " + t);	
	}

	public void run(){
		try {
			for(int i = 5; i > 0; i--){
				switch(name){
					case "BMS":
						System.out.println(name);
						Thread.sleep(10000);
						break;
					case "CSE":
						System.out.println(name);
						Thread.sleep(2000);
						break;
					default:
						System.out.println("");
						break;
				}
			}
		}
		
		catch(InterruptedException ie)
			{System.out.println("Child interrupted");}
		System.out.println("Exiting thread: " + name);
	}

	public static void main(String arg[]){
		Lab a1 = new Lab("BMS");
		Lab a2 = new Lab("CSE");
		
		a1.t.start();
		a2.t.start();
		
		try{
			for(int i = 5; i > 0; i--){
				Thread.sleep(10000);
			}
			
		}
		catch(InterruptedException ie)
			{System.out.println("Main thread interrupted");}

		System.out.println("Child threads exiting");	
	}
}



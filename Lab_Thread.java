class Lab_Thread implements Runnable {
	Thread t;
	String name;
	Lab_Thread(String th){
		name = th;
		t = new Thread(this, th);
		System.out.println("Child thread: " + t);	
	}

	public void run(){
		try {
			for(int i = 5; i > 0; i--){
				switch(name){
					case "BMS College of Engineering":
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
		Lab_Thread a1 = new Lab_Thread("BMS");
		Lab_Thread a2 = new Lab_Thread("CSE");
		
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



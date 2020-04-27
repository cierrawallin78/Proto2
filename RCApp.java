package extracredit;

import java.util.*;

public class RCApp {
	

	
	public static void main (String [] args){

		ListPicker List = new ListPicker(); //initializes list element where user can choose HC-06 module
		Bluetooth connection = new Bluetooth();//initializes Bluetooth client
		Button forward = new Button(); ////creates instance of button for use of forwards
		Button backward = new Button();//creates instance of button for use of backwards
		Button left = new Button();//creates instance of button for use of left
		Button right = new Button();//creates instance of button for use of right
		Button stop = new Button();//creates instance of button for use of stop
		Button slow = new Button(); //creates instance of button for use of slow speed
		Button medium = new Button();//creates instance of button for use of medium speed
		Button fast = new Button();//creates instance of button for use of fast speed
		String move = "S";//initializes ascii character sent to HC-06 module as 'S'
		
		
		forward.setColor("Blue"); //sets forwards button to blue
		backward.setColor("Blue");//sets backward button to blue
		left.setColor("Blue");//sets left button to blue
		right.setColor("Blue");//sets right button to blue
		stop.setColor("Gold");//sets stop button to gold
		slow.setColor("Light Gray");//sets slow button to light gray
		medium.setColor("Gray");//sets medium button to gray
		fast.setColor("Black");//sets fast button to black
		
		
		//sets locations of buttons upon screen
		forward.setCenter(0,100);
		backward.setCenter(0,-100);
		left.setCenter(-100,0);
		right.setCenter(100,0);
		stop.setCenter(0,0);
		System.out.println("Speed:");
		slow.setCenter(-150,-150);
		medium.setCenter(-125,-150);
		fast.setCenter(-100,-150);
		
		//Acquires a list of elements of Bluetooth clients 
		while (List.BeforePicking()) {
			String elem = List.elements();
			elem = connection.Addresses();
			
			
			
		}
		
		//chooses HC-06 module and attempts to connect
		//Prints Connected if connection is successful
		while(List.AfterPicking()) {
			String check = List.Selection();
			check = connection.ConnectAdress(check);
			String text = List.Text();
			text = "Connected";
			if (List.Connected()) {
				
			
			System.out.println(text);
			}
		}
		
		
		
		//while the forward button is pressed, ascii character 'F' is sent
		while(forward.Touch()) {
			move = "F";
			connection.SendText(move);
			
		}
		//when any button is no longer being touched, ascii character 'S' is automatically sent
		while(forward.TouchUp()) {
			move = "S";
			connection.SendText(move);
		}
		
		//while the backward button is pressed, ascii character 'B' is sent
		while(backward.Touch()) {
			move = "B";
			connection.SendText(move);
			
		}
		
		while(backward.TouchUp()) {
			move = "S";
			connection.SendText(move);
		}
		
		//while the left button is pressed, ascii character 'L' is sent
		while(left.Touch()) {
			move = "L";
			connection.SendText(move);
			
		}
		
		while(left.TouchUp()) {
			move = "S";
			connection.SendText(move);
		}
		
		//while the right button is pressed, ascii character 'R' is sent
		while(right.Touch()) {
			move = "R";
			connection.SendText(move);
		}
		
		while(right.TouchUp()) {
			move = "S";
			connection.SendText(move);
		}
		//while the stop button is pressed, ascii character 'S' is sent
		while(stop.Touch()) {
			move = "S";
			connection.SendText(move);
		}
		while(stop.TouchUp()) {
			move = "S";
			connection.SendText(move);
		}
		//while the slow button is pressed, ascii character '1' is sent
		while(slow.Touch()) {
			move = "1";
			connection.SendText(move);
		}
		//while the medium button is pressed, ascii character '2' is sent
		while(medium.Touch()) {
			move = "2";
			connection.SendText(move);
			
		}
		//while the fast button is pressed, ascii character '3' is sent
		while(fast.Touch()) {
			move = "3";
			connection.SendText(move);
			
		}
		
		
		
		
	
	
	

	}
	
}

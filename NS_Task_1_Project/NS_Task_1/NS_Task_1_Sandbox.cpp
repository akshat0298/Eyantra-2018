#include "NS_Task_1_Sandbox.h"
int count_node = 0;
/*
*
* Function Name: forward_wls
* Input: node
* Output: void
* Logic: Uses white line sensors to go forward by the number of nodes specified
* Example Call: forward_wls(2); //Goes forward by two nodes
*
*/
void forward_wls(unsigned char node)
{
	
}
/*
*
* Function Name: left_turn_wls
* Input: void
* Output: void
* Logic: Uses white line sensors to turn left until black line is encountered
* Example Call: left_turn_wls(); //Turns right until black line is encountered
*
*/
void left_turn_wls(void)
{

}

/*
*
* Function Name: right_turn_wls
* Input: void
* Output: void
* Logic: Uses white line sensors to turn right until black line is encountered
* Example Call: right_turn_wls(); //Turns right until black line is encountered
*/
void right_turn_wls(void)
{

}

/*
*
* Function Name: Square
* Input: void
* Output: void
* Logic: Use this function to make the robot trace a square path on the arena
* Example Call: Square();
*/
void Square(void)
{
	forward();
	_delay_ms(1000);
	stop();
	_delay_ms(100);
	left();
	_delay_ms(450);
	forward();
	_delay_ms(1000);
	stop();
	_delay_ms(100);
	left();
	_delay_ms(450);
	forward();
	_delay_ms(1000);
	stop();
	_delay_ms(100);
	left();
	_delay_ms(450);
	forward();
	_delay_ms(1000);
	stop();
	_delay_ms(100);
	left();
	_delay_ms(450);
	forward();
	_delay_ms(1000);
	stop();
	_delay_ms(3000);
}


/*
*
* Function Name: Task_1_1
* Input: void
* Output: void
* Logic: Use this function to encapsulate your Task 1.1 logic
* Example Call: Task_1_1();
*/
void Task_1_1(void)
{
	unsigned char left_sensor, middle_sensor, right_sensor,cur_left, cur_middle, cur_right;
	left_sensor = ADC_Conversion(1);
	_delay_ms(3);
	middle_sensor = ADC_Conversion(2);
	_delay_ms(3);
	right_sensor = ADC_Conversion(3);
	_delay_ms(3);
	printf("\n   %d    %d     %d    %d", left_sensor, middle_sensor, right_sensor, count_node);
	
	while (true)
	{
		if (count_node == 13)
		{
			break;
		}
		left_sensor = ADC_Conversion(1);
		_delay_ms(3);
		middle_sensor = ADC_Conversion(2);
		_delay_ms(3);
		right_sensor = ADC_Conversion(3);
		_delay_ms(3);
		printf("\n   %d    %d     %d    %d", left_sensor, middle_sensor, right_sensor,count_node);
		if (middle_sensor == 255 && left_sensor == 0 && right_sensor==0)
		{
			forward();
			velocity(170, 170);
		}
		else if (left_sensor == 255 && middle_sensor == 255 && right_sensor == 0)
		{
			left();
			velocity(20, 20);
		
		}
		else if (left_sensor == 0 && middle_sensor == 255 && right_sensor == 255)
		{
			right();
			velocity(20, 20);
		
		}
		else if (left_sensor == 255 && middle_sensor == 0 && right_sensor == 0)
		{
			soft_left();
			velocity(40, 40);
		}
		else if (left_sensor == 0 && middle_sensor == 0 && right_sensor == 255)
		{
			soft_right();
			velocity(40, 40);
		}
		else if (left_sensor == 0 && middle_sensor == 0 && right_sensor == 0)
		{
			back();
			velocity(50, 50);
		}
		else if (left_sensor ==255 && middle_sensor == 0 && right_sensor == 255)
		{
			forward();
			velocity(50, 50);
		}
		else if (left_sensor == 255 && middle_sensor == 255 && right_sensor == 255)
		{
			forward();
			_delay_ms(50);
			cur_left = ADC_Conversion(1);
			_delay_ms(3);
			cur_middle = ADC_Conversion(2);
			_delay_ms(3);
			cur_right = ADC_Conversion(3);

			if (cur_left == left_sensor && middle_sensor == cur_middle && right_sensor == cur_right)
			{
				count_node++;
				switch (count_node)
				{
				case 1:
					forward();
					_delay_ms(230);
					right();
					_delay_ms(450);
					break;

				case 2:
					stop();
					_delay_ms(10);
					forward();
					velocity(127, 127);
					_delay_ms(600);
					soft_left();
					_delay_ms(225);
					break;

				case 3:
					forward();
					_delay_ms(135);
					soft_left();
					_delay_ms(300);
					break;

				case 4:
					forward();
					_delay_ms(200);
					stop();
					_delay_ms(10);
					left();
					_delay_ms(390);
					break;

				case 5:
					forward();
					_delay_ms(200);
					right();
					_delay_ms(600);
					break;

				case 6:
				case 7:
					forward();
					_delay_ms(250);
					break;

				case 8:
					forward();
					_delay_ms(175);
					right();
					_delay_ms(570);
					break;

				case 9:
					forward();
					_delay_ms(225);
					left();
					_delay_ms(435);
					break;

				case 10:
					forward();
					_delay_ms(200);
					left();
					_delay_ms(190);
					break;


				case 11:
					stop();
					_delay_ms(20);
					forward();
					_delay_ms(250);
					left();
					_delay_ms(180);
					break;

				case 12:
					forward();
					_delay_ms(215);
					right();
					_delay_ms(430);
					break;

				case 13:
					forward();
					_delay_ms(200);
					stop();
					_delay_ms(10);
					break;

				}
			}

		}
		else
		{
			stop();
			break;
		}


	}

}

/*
*
* Function Name: Task_1_2
* Input: void
* Output: void
* Logic: Use this function to encapsulate your Task 1.2 logic
* Example Call: Task_1_2();
*/
void Task_1_2(void)

{
		unsigned char left_sensor, middle_sensor, right_sensor, cur_left, cur_middle, cur_right;
		while (true)
		{
			_delay_ms(2);
			left_sensor = ADC_Conversion(1);
			middle_sensor = ADC_Conversion(2);
			right_sensor = ADC_Conversion(3);
			if (middle_sensor == 255 && left_sensor == 0 && right_sensor == 0)
			{
				forward();
				velocity(150, 150);
			}
			else if (left_sensor == 255 && middle_sensor == 255 && right_sensor == 0)
			{
				left();
				velocity(20, 20);

			}
			else if (left_sensor == 0 && middle_sensor == 255 && right_sensor == 255)
			{
				right();
				velocity(20, 20);
			}
			else if (left_sensor == 255 && middle_sensor == 0 && right_sensor == 0)
			{
				soft_left();
				velocity(40, 40);
			}
			else if (left_sensor == 0 && middle_sensor == 0 && right_sensor == 255)
			{
				soft_right();
				velocity(40, 40);
			}
			else if (left_sensor == 0 && middle_sensor == 0 && right_sensor == 0)
			{
				back();
				velocity(50, 50);
			}
			else if (left_sensor == 255 && middle_sensor == 0 && right_sensor == 255)
			{
				forward();
				velocity(50, 50);
			}
			else if (left_sensor == 255 && middle_sensor == 255 && right_sensor == 255)
			{
				forward();
				_delay_ms(65);
				cur_left = ADC_Conversion(1);
				cur_middle = ADC_Conversion(2);
				cur_right = ADC_Conversion(3);
			
				// the above piece of code helps the bot to differentiate between a node and a line by making is move forward for 50ms then again reading the reading and comparing the values 
				if (cur_left == left_sensor && middle_sensor == cur_middle && right_sensor == cur_right)
				{
					forward();
					_delay_ms(270);
					printf("Detected a node");
				}

			}
			
		}
}



/*
*
* Function Name: line_follow()
* Input: void
* Output: void
* Logic: Use this function to make the robot to follow the path given
* Example Call: line_follow();
*/
void line_follow(void)
{

}


void test()
{
	right();
	_delay_ms(450);
	stop();
	_delay_ms(3000);
}
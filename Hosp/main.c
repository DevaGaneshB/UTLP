
#include "macros.h"
#include <ulk.h>

int main(void) PROGRAM_ENTRY;

int main()

{

	  struct PIXEL
	  {
	  	unsigned int x;
	  	unsigned int y;
	  };
	  extern struct PIXEL pixel;
	  extern struct PIXEL ulk_proc_touch_spi_enable(void);
	  extern struct PIXEL ulk_proc_touch_spi_poll(void);
	  extern void ulk_proc_touch_spi_disable(void);
	int row=0,column=0, *address = 0x80500000;
	int t1=0,t2=0,t3=0,t4=0,t5=0,t6=0,t7=0,t8=0;
	int i,fd,sd,td,frd,dd;

	for(row=0;row<79;row++)
	{
		for(column=0; column<105; column++)
		{
			*(address+(row*320)+column) = 0xff0000;
		}
	}
	for(row=0;row<79;row++)
	{
		for(column=107; column<211; column++)
		{
			*(address+(row*320)+column) = 0x00ff00;
		}
	}
	for(row=0;row<79;row++)
	{
		for(column=213; column<320; column++)
		{
			*(address+(row*320)+column) = 0x0000ff;
		}
	}
	for(row=81;row<159;row++)
		{
			for(column=0; column<105; column++)
			{
				*(address+(row*320)+column) = 0xffff00;
			}
		}
	for(row=81;row<159;row++)
			{
				for(column=107; column<211; column++)
				{
					*(address+(row*320)+column) = 0xFF8C00;
				}
			}

	for(row=81;row<159;row++)
			{
				for(column=213; column<320; column++)
				{
					*(address+(row*320)+column) = 0xD2691E;
				}
			}

	for(row=161;row<239;row++)
				{
					for(column=107; column<211; column++)
					{
						*(address+(row*320)+column) = 0x000000;
					}
				}
	for(row=161;row<239;row++)
					{
						for(column=0; column<105; column++)
						{
							*(address+(row*320)+column) = 0xffffff;
						}
					}


	for(row=161;row<239;row++)
				{
					for(column=213; column<320; column++)
					{
						*(address+(row*320)+column) = 0xff00ff;
					}
				}
	ulk_fpga_clcd_init();
			       		ulk_fpga_clcd_display_on();
			       		ulk_fpga_clcd_display_clear();
			       		ulk_fpga_clcd_cursor_home();
			       		ulk_fpga_clcd_display_string("RED-Cardio GREEN-Neuro YELLOW-Gynec ORANGE-Ortho BLACK-Gastro BLUE-Pediatrics BROWN-Dental PURPLE-Urology ");


	ulk_proc_touch_spi_enable();
		       while(1)
		       {
		       	pixel=ulk_proc_touch_spi_poll();
		       	if (pixel.x<=105 && pixel.y>=160)
		       	{
		       		t1++;
		       		ulk_cpanel_printf(" Xpos: %d\n YPos: %d\n", pixel.x,pixel.y);
		       	 ulk_fpga_clcd_init();
		       		ulk_fpga_clcd_display_on();
		       		ulk_fpga_clcd_display_clear();
		       		ulk_fpga_clcd_cursor_home();
		       		ulk_fpga_clcd_display_string("1-Dr.Divya 2-Dr.Deepika");
		            ulk_fpga_7seg_led_enable();

		               fd = t1%10;
		       		   sd = ((t1/10)%10)*16;
		                	   td = ((t1/100)%10)*16*16;
		       		   frd= (t1/1000)*16*16*16;
		       		   dd = fd+sd+td+frd;
		       	   	   ulk_fpga_7seg_led_write(dd);
		       	   	   ulk_proc_delay(ULK_SEC(5));
		       	   	   ulk_fpga_7seg_led_disable();




		       	}
		    	if (pixel.x<=105 && pixel.y>=79 && pixel.y<=159)
		    			       	{
									t2++;
		    			       		ulk_cpanel_printf(" Xpos: %d\n YPos: %d\n", pixel.x,pixel.y);
		    			       		ulk_fpga_clcd_display_string("1-Dr.Bavani 2-Dr.Sridaran");
		    			            ulk_fpga_7seg_led_enable();

		    			               fd = t2%10;
		    			       		   sd = ((t2/10)%10)*16;
		    			                	   td = ((t2/100)%10)*16*16;
		    			       		   frd= (t2/1000)*16*16*16;
		    			       		   dd = fd+sd+td+frd;
		    			       	   	   ulk_fpga_7seg_led_write(dd);
		    			       	   	   ulk_proc_delay(ULK_SEC(5));
		    			       	   	   ulk_fpga_7seg_led_disable();

		    			       	}
		    	if (pixel.x>=105 && pixel.x<=212 && pixel.y>=159)
		    				       	{
										t3++;
		    				       		ulk_cpanel_printf(" Xpos: %d\n YPos: %d\n", pixel.x,pixel.y);

		    				       		ulk_fpga_clcd_display_string("1-Dr.Arjun 2-Dr.Sai Krishna");
		    				            ulk_fpga_7seg_led_enable();

		    				               fd = t3%10;
		    				       		   sd = ((t3/10)%10)*16;
		    				                	   td = ((t3/100)%10)*16*16;
		    				       		   frd= (t3/1000)*16*16*16;
		    				       		   dd = fd+sd+td+frd;
		    				       	   	   ulk_fpga_7seg_led_write(dd);
		    				       	   	   ulk_proc_delay(ULK_SEC(5));
		    				       	   	   ulk_fpga_7seg_led_disable();

		    				       	}
		    	if (pixel.x>=105 && pixel.x<=212 && pixel.y>=80 && pixel.y<=159)
		    				       	{
										t4++;
		    				       		ulk_cpanel_printf(" Xpos: %d\n YPos: %d\n", pixel.x,pixel.y);

		    				       		ulk_fpga_clcd_display_string("1-Dr.Balamurugan 2-Dr.Sherin");
		    				            ulk_fpga_7seg_led_enable();

		    				               fd = t4%10;
		    				       		   sd = ((t4/10)%10)*16;
		    				                	   td = ((t4/100)%10)*16*16;
		    				       		   frd= (t4/1000)*16*16*16;
		    				       		   dd = fd+sd+td+frd;
		    				       	   	   ulk_fpga_7seg_led_write(dd);
		    				       	   	   ulk_proc_delay(ULK_SEC(5));
		    				       	   	   ulk_fpga_7seg_led_disable();

		    				       	}
		    	if (pixel.x>=105 && pixel.x<=212 && pixel.y<=79)
		    				       	{
										t5++;
		    				       		ulk_cpanel_printf(" Xpos: %d\n YPos: %d\n", pixel.x,pixel.y);
		    				       		ulk_fpga_clcd_display_string("1-Dr.Aarthy 2-Dr.Tejaswini");
		    				            ulk_fpga_7seg_led_enable();

		    				               fd = t5%10;
		    				       		   sd = ((t5/10)%10)*16;
		    				                	   td = ((t5/100)%10)*16*16;
		    				       		   frd= (t5/1000)*16*16*16;
		    				       		   dd = fd+sd+td+frd;
		    				       	   	   ulk_fpga_7seg_led_write(dd);
		    				       	   	   ulk_proc_delay(ULK_SEC(5));
		    				       	   	   ulk_fpga_7seg_led_disable();

		    				       	}
		    	if (pixel.x>=213 && pixel.y>=159)
		    					       	{
											t6++;
		    					       		ulk_cpanel_printf(" Xpos: %d\n YPos: %d\n", pixel.x,pixel.y);
		    					       		ulk_fpga_clcd_display_string("1-Dr.John Martin 2-Dr.Shilpa");
		    					            ulk_fpga_7seg_led_enable();

		    					               fd = t6%10;
		    					       		   sd = ((t6/10)%10)*16;
		    					                	   td = ((t6/100)%10)*16*16;
		    					       		   frd= (t6/1000)*16*16*16;
		    					       		   dd = fd+sd+td+frd;
		    					       	   	   ulk_fpga_7seg_led_write(dd);
		    					       	   	   ulk_proc_delay(ULK_SEC(5));
		    					       	   	   ulk_fpga_7seg_led_disable();

		    					       	}
		    	if (pixel.x>=213 && pixel.y>=79 && pixel.y<=159)
		    					       	{
											t7++;
		    					       		ulk_cpanel_printf(" Xpos: %d\n YPos: %d\n", pixel.x,pixel.y);
		    					       		ulk_fpga_clcd_display_string("1-Dr.Karunya 2-Dr.Shanmathi");
		    					            ulk_fpga_7seg_led_enable();

		    					               fd = t7%10;
		    					       		   sd = ((t7/10)%10)*16;
		    					                	   td = ((t7/100)%10)*16*16;
		    					       		   frd= (t7/1000)*16*16*16;
		    					       		   dd = fd+sd+td+frd;
		    					       	   	   ulk_fpga_7seg_led_write(dd);
		    					       	   	   ulk_proc_delay(ULK_SEC(5));
		    					       	   	   ulk_fpga_7seg_led_disable();

		    					       	}
		    	if (pixel.x>=213 && pixel.y<=79)
		    				       	{
										t8++;
		    				       		ulk_cpanel_printf(" Xpos: %d\n YPos: %d\n", pixel.x,pixel.y);
		    				       		ulk_fpga_clcd_display_string("1-Dr.Koushik 2-Dr.Swarnalatha");
		    				            ulk_fpga_7seg_led_enable();

		    				               fd = t8%10;
		    				       		   sd = ((t8/10)%10)*16;
		    				                	   td = ((t8/100)%10)*16*16;
		    				       		   frd= (t8/1000)*16*16*16;
		    				       		   dd = fd+sd+td+frd;
		    				       	   	   ulk_fpga_7seg_led_write(dd);
		    				       	   	   ulk_proc_delay(ULK_SEC(5));
		    				       	   	   ulk_fpga_7seg_led_disable();

		    				       	}
		    	if(pixel.x<=105 && pixel.y<=79  )
		    	{		ulk_cpanel_printf(" Xpos: %d\n YPos: %d\n", pixel.x,pixel.y);
						ulk_fpga_clcd_display_string("Loading...");
						ulk_fpga_clcd_display_string("RED-Cardio GREEN-Neuro YELLOW-Gynec ORANGE-Ortho BLACK-Gastro BLUE-Pediatrics BROWN-Dental PURPLE-Urology ");
		    	}

		       		}





	ulk_proc_touch_spi_enable();

for(row=0;row<240;row++)
	{
		for(column=0; column<320; column++)
		{
			*(address+(row*320)+column) = 0x000000;
		}
	}



	ulk_fpga_clcd_display_off();





	return 0;

}

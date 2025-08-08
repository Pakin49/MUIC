// Pakin Panawattanakul 6580043
// in this version if the time is exactly the same it will show 24 hours (tomorrow)

package Ex1_6580043;

import java.util.*;

public class Exercise_E1
{
    public static void main(String[] args)
    {
        System.out.println("=== Start time ===");
        int start_hour, start_min;
        int end_hour, end_min;
        start_hour = get_hour();
        start_min = get_minute();

        System.out.println();
        System.out.println("=== End time ===");
        end_hour = get_hour();
        end_min = get_minute();

        int start_time = (start_hour*60)+start_min;
        int end_time = (end_hour*60)+end_min;

        System.out.println();
        if (end_time>start_time){
            System.out.printf("Start time = %02d:%02d, End time = %02d:%02d (today)\n",start_hour,start_min,end_hour,end_min);
        }
        else{
            end_time += 1440;
            System.out.printf("Start time = %02d:%02d, End time = %02d:%02d (tomorrow)\n",start_hour,start_min,end_hour,end_min);
        }
        int Dif = end_time - start_time;
        System.out.println("Duration = " + Dif/60 + " hours, " + Dif%60 + " minutes");
    }

    public static int get_hour()
    {
        int hour = -1;
        Scanner scan = new Scanner(System.in);
        while (true) {
            System.out.println("Enter hour digit (0-23) = ");
            try {
                hour = scan.nextInt();
                if (hour >= 0 && hour < 24) {
                    break;
                } else {
                    System.out.println("Invalid hour. Please enter a number between 0 and 23.");
                }
            }
            catch (Exception e) {
                System.out.println("Invalid input. Please enter a valid integer.");
                scan.nextLine();
            }
        }
        return hour;
    }

    public static int get_minute()
    {
        Scanner scan = new Scanner(System.in);
        int minute = -1;
        while (true) {
            System.out.println("Enter minute digit (0-59) = ");
            try {
                minute = scan.nextInt();
                if (minute >= 0 && minute < 60) {
                    break;
                }
                else {
                    System.out.println("Invalid minute. Please enter a number between 0 and 59.");
                }
            } catch (Exception e) {
                System.out.println("Invalid input. Please enter a valid integer.");
                scan.nextLine();
            }
        }
        return minute;
    }
}

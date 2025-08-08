// Pakin Panawattanakul 6580043
package Ex2_6580043;

import java.io.*;
import java.util.*;

public class Exercise_E2 {
    public static void main(String[] args){

        //get Path for input and output file
        String path = "src/main/java/Ex2_6580043";
        String inputPath = path + "/platforms.txt";
        System.out.println(inputPath);
        String outputPath = path + "/output.txt";

        try {
            //Initialize scanner for input file
            File inputFile = new File(inputPath);
            Scanner fileScan = new Scanner(inputFile);
            System.out.println("Read platform data from " + inputPath);

            //get MAU threshold from System.in
            Scanner scan = new Scanner(System.in);
            System.out.println("Enter MAU threshold in millions = ");
            int MAUThreshold = scan.nextInt(); scan.nextLine();

            //Initialize PrintWriter for output file
            File outputFile = new File(outputPath);
            PrintWriter filePrint = new PrintWriter(new FileWriter(outputFile, false));
            System.out.println("Write output "+outputPath);

            //Print header for output file
            filePrint.printf("Platform        MAU(thousands)     MAU(billions)    >%,d millions\r\n",MAUThreshold);
            for(int i=0;i<67;i++){filePrint.print('=');}
            filePrint.printf("\r\n");

            //read and calculate MAU in thousand and million
            while(fileScan.hasNext()){
                String platform = fileScan.next();
                int MAU_M = fileScan.nextInt();
                int MAU_T = MAU_M*1000;
                double MAU_B = (double)MAU_M/1000;

                //Write and formating output file
                filePrint.printf("%-16s%,11d%,17.3f",platform,MAU_T,MAU_B);
                for(int i=0;i<13;i++){filePrint.print(' ');}
                if(MAU_M>MAUThreshold){
                    filePrint.printf("yes\r\n");
                }
                else{
                    filePrint.printf("no\r\n");
                }
            }

            //Close Scanner and PrintWriter
            fileScan.close();
            filePrint.close();
        }
        //catch exception and print error message
        catch(Exception e){
            System.err.println(e.getMessage());
        }
    }
}

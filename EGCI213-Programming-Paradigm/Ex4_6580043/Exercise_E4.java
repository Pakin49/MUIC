//Pakin Panawattanakul 6580043

package Ex4_6580043;

import java.util.*;
import java.io.*;

class Company implements Comparable <Company> {
    private String name;
    private int year, marketValue, profit, sales;

    public Company(){super();}
    public Company(String n, int y, int m, int p, int s) {
        this.name = n;
        this.year = y;
        this.marketValue = m;
        this.profit = p;
        this.sales = s;
    }

    @Override
    // this will sort in Descending order by switching other_company and this
    public int compareTo(Company other_company) {
        int result = Integer.compare(other_company.marketValue, this.marketValue);
        if (result == 0) result = Integer.compare(other_company.profit, this.profit);
        if (result == 0) result = Integer.compare(other_company.sales, this.sales);
        if (result == 0) result = this.name.compareTo(other_company.name);
        return result;
    }

    public void printCompany(){
        System.out.printf("%-20s (%4d)       %,12d          %,6d          %,5d\n",this.name,this.year,this.marketValue,this.profit,this.sales);
    }
}

public class Exercise_E4 {
    public static void main(String[] args) {
        boolean fininshed = false;
        do {
            try {
                // --- Get year threshold ---
                Scanner key_scan = new Scanner(System.in);
                System.out.println("Enter year threshold = ");
                int threshold = key_scan.nextInt();
                key_scan.nextLine();

                // --- Handling File and Scanner ---
                String company_file_path = "src/main/java/Ex4_6580043/companies.txt";
                File company_file = new File(company_file_path);
                Scanner company_file_scan = new Scanner(company_file);
                company_file_scan.nextLine(); //skip the first line
                System.out.println("Company established since 1000    Market Value($Bn.)    Profit($Bn.)    Sales($Bn.)");
                System.out.println("====================================================================================");

                // --- Data into ArrayList ---
                ArrayList<Company> Companies_list = new ArrayList<>();
                while (company_file_scan.hasNext()) {
                    String line = company_file_scan.nextLine();
                    String[] col = line.split(",");
                    String name = col[0];
                    int year = Integer.parseInt(col[1].trim());
                    if (year < threshold) {
                        continue;
                    }
                    int market_value = Integer.parseInt(col[2].trim());
                    int profits = Integer.parseInt(col[3].trim());
                    int sales = Integer.parseInt(col[4].trim());
                    Companies_list.add(new Company(name, year, market_value, profits, sales));
                }

                Collections.sort(Companies_list);
                for (Company company : Companies_list) {
                    company.printCompany();
                }

                // Ask for repeat
                System.out.println("\n\nEnter y or Y to continue, else to quit =");
                String next = key_scan.nextLine();
                if(!next.equalsIgnoreCase("y")) {fininshed = true;}

            } catch (Exception e) {
                System.err.println("Enter valid number (Integer)");
            }
        }while(!fininshed);
    }
}

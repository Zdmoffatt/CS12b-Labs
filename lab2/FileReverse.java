/*
Zachary Moffatt
zmoffatt
CS12m
4/10/16
Lab2
FileReverse.java
Takes in two files, tokenises the strings in the first file and reverses them before printing them into the second file
*/
import java.io.*;
import java.util.Scanner;

class FileReverse{
    public static void main(String[] args) throws IOException{
        if(args.length!=2){
            System.out.println("Incorrect arguments. Usage: FileCopy <input file> <output file>");
            System.exit(1);
        }
        int line=0,counter=0;
        String currentLine = null;
        String[] tokens = null;
        Scanner input = new Scanner(new File(args[0]));
        PrintWriter output = new PrintWriter(new FileWriter(args[1]));

        while(input.hasNextLine()){
            line++;
            currentLine=input.nextLine().trim()+" ";
            tokens = currentLine.split("\\s+");
            counter= 0;
            while(counter<tokens.length){
                System.out.println(stringReverse(tokens[counter],tokens[counter].length()));
                output.println(stringReverse(tokens[counter],tokens[counter].length()));
                counter++;
            }
        }

        input.close();
        output.close();
    }
    public static String stringReverse(String s, int n){
        if(n>0){
            char let = s.charAt(n-1);
            String t = new String(String.valueOf(let) + stringReverse(s,n-1));
            return t;
        }
        else{
            return "";
        }
    }
}
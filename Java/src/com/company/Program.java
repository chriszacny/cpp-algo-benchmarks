package com.company;

import java.io.*;
import java.util.HashMap;

public class Program
{

    public static final int LOWER_NUMBER_BOUND = 1000000;
    public static final int UPPER_NUMBER_BOUND = 9999999;

    private String pathToFile;
    private HashMap<Integer, Boolean> map = new HashMap<Integer, Boolean>();

    public Program(String[] args)
    {
        pathToFile = args[0];
    }

    public void run()
    {
        readDataIntoMap(pathToFile);
        writeDataToOutputFile();
    }

    private void writeDataToOutputFile()
    {
        String outputFilename = String.format("%s.bitmapsort", pathToFile);
        Writer writer = null;
        String newline = System.getProperty("line.separator");
        try
        {

            writer = new BufferedWriter(new FileWriter(outputFilename));
            for (Integer i = LOWER_NUMBER_BOUND; i <= UPPER_NUMBER_BOUND; i++)
            {
                Boolean value = map.get(i);
                if (value != null)
                {
                    writer.write(String.format("%s%s", i.toString(), newline));
                }
            }
        }
        catch (IOException ex)
        {
            System.out.println(String.format("ERROR; could not write to %s", outputFilename));
        }
        finally
        {
            try {
                if (writer != null)
                {
                    writer.close();
                }
                else
                {
                    throw new IOException();
                }
            }
            catch (IOException ex)
            {
                System.out.println(String.format("ERROR; could not close %s", outputFilename));
            }
        }
    }

    private void readDataIntoMap(String pathToFile)
    {
        BufferedReader bufferedReader = null;
        try
        {
            bufferedReader = new BufferedReader(new FileReader(pathToFile));
            String line;
            while ((line = bufferedReader.readLine()) != null)
            {
                int number = Integer.parseInt(line);
                map.put(number, true);
            }
        }
        catch (FileNotFoundException ex)
        {
            System.out.println(String.format("ERROR; could not find %s", pathToFile));
        }
        catch (IOException ex)
        {
            System.out.println(String.format("ERROR; could not read from file %s", pathToFile));
        }
        finally
        {
            try
            {
                if (bufferedReader != null)
                {
                    bufferedReader.close();
                }
                else
                {
                    throw new IOException();
                }
            }
            catch (IOException ex)
            {
                System.out.println(String.format("ERROR; could not close %s", pathToFile));
            }
        }
    }
}

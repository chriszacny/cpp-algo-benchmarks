package com.company;

public class Main {

    public static void main(String[] args) {
        Program p = new Program(args);
        long start = System.currentTimeMillis();
        p.run();
        long end = System.currentTimeMillis();
        long diff = end - start;
        System.out.println(String.format("Program took %s milliseconds", diff));
    }
}

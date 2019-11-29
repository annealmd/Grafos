/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package poo_interface;

import java.io.File;
import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author Asus
 */
public class POO_interface 
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        
        try{
        File file = new File("/home/anne/Desktop/IFNMG/2_POO/file.txt"); //args[0]
        Scanner input = new Scanner(file);
        String type = input.nextLine();
        Cities_abst x;
        if(type.equals(new String("POS")))
            x = new Pos();
        else
            x = new Ma();
        
        x.setCities(input.nextInt());        
        String string = input.nextLine();        
        x.loadFile(input);        
           try
            {
                //System.out.println("\nDistancia entre 3 e 0: "+((Ma)x).checkDist(2,0));
                System.out.println("\nDistancia entre 2 e 0: "+ x.checkDist(2,0));
                System.out.println("\nDistancia entre 2 e 1: "+ x.checkDist(2,1));
                System.out.println("\nDistancia entre 2 e 3: "+ x.checkDist(2,3));
                
                System.out.println("\n Cidade proxima de 2: " + x.nearCity(2));
            }catch (Exception e) 
            {
                System.out.println(e.toString());
            }
       } catch(IOException e)
        {
            System.out.println("Could not open the file!");
        }
        
    }
    
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package poo_interface;

import java.util.ArrayList;
import java.util.Scanner;


/**
 *
 * @author Asus
 */
public class Ma extends Cities_abst 
{
    private ArrayList<ArrayList<Double>> matrix = new ArrayList<ArrayList<Double>>(getCities());
        
    @Override
    public void loadFile(Scanner input)
    {
        System.out.println(" "+ getCities());
        for(int i=0; i<getCities(); i++)
        {
            String string = input.nextLine(); // real the whole line to a String
            String[] strArray = string.split(" "); 
            //System.out.println("sr" + string);
            Double x = Double.parseDouble(strArray[0]);
            Double y = Double.parseDouble(strArray[1]);
            Double z = Double.parseDouble(strArray[2]);
            Double w = Double.parseDouble(strArray[3]);
            ArrayList<Double> arr = new ArrayList<Double>();
            arr.add(x); arr.add(y); arr.add(z);arr.add(w);
            matrix.add(arr);
            System.out.println(x+" "+ y+ " "+ z+ " "+ w);            
                     
        }
        System.out.println("\nShowing Matrix:\n"+ matrix);
        
    }
    
    @Override
    public Double checkDist(int A, int B) //throws Invalid_City
    {   //System.out.println("Distance between: "+ A + " and "+ B +
                            //" -> "+matrix.get(A).get(B));
        return matrix.get(A).get(B);
    }
    
    @Override
    public int nearCity(int A)
    {
        Double dist = 98765.9876;
        int near = 45;
        for(int i=0; i< getCities(); i++)            
        {
            if(i!=A && (matrix.get(A).get(i)< dist))
            {
                dist = matrix.get(A).get(i);
                near = i;
                //System.out.println("\n *Cidade: "+ i +" dist: "+ dist);
            }            
            
        }
        //System.out.println("Nearest City from "+ A + " -> "+ near);
        return near;
    }
        
}

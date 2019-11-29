/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package poo_interface;

import java.awt.geom.Point2D;
import java.util.ArrayList;
import java.util.Scanner;

public class Pos extends Cities_abst 
{
    ArrayList<Point2D> coord = new ArrayList<Point2D>();
    
    @Override
    public void loadFile(Scanner input)
    {
        System.out.println(" "+ getCities());
        for(int i=0; i<getCities(); i++)
        {
            String string = input.nextLine();
            String[] strArray = string.split(" ");
            //System.out.println("sr" + string);
            float x = Float.parseFloat(strArray[0]);
            float y = Float.parseFloat(strArray[1]);

            System.out.println(x+" "+ y);
            //System.out.println(y);
            
            Point2D p = new Point2D.Float(x,y);            
            coord.add(p);         
        }
        System.out.println("\nShowing Points:"+ coord);
        
    }
    
    @Override
    public Double checkDist(int A, int B)
    {
        Double distFirst = Math.pow((double)(coord.get(A).getX() - coord.get(B).getX()),2);
        Double distSecond = Math.pow((double)(coord.get(A).getY() - coord.get(B).getY()),2);
        Double dist = Math.sqrt(distFirst+ distSecond);
        return dist;
    }
    @Override
    public int nearCity(int A)
    {
        int near = 0;
        double dist =  4328.99;
        for(int i=0; i<coord.size(); i++ )
        {
            double aux = checkDist(A, i);
            if(i!=A && aux < dist )
            {
                dist = aux; near = i;                
            }                
        }
        
        return near;        
    }

    public void printing() 
    {
        for(Point2D p : coord)
        {
            System.out.println(p.getX()+ " "+ p.getY()+" \n");
            
        }
    }
}

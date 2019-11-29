/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package poo_interface;

import java.util.Scanner;

/**
 *
 * @author Asus
 */
public abstract class Cities_abst implements dist_check
{
    protected int cities;
    
    public abstract void loadFile(Scanner input);
    
    public int getCities() {
        return cities;
    }

    
    public void setCities(int cities) {
        this.cities = cities;
    }
    
    public Double checkDist(int A, int B) //throws Invalid_City
    {
        return checkDist(A, B);
    }
    public int nearCity(int A)
    {
        return nearCity(A);
    }
            
    
    
}

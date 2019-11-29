/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package poo_interface;

/**
 *
 * @author Asus
 */
public interface dist_check 
{
    public abstract Double checkDist(int A, int B); //throws Invalid_City;
    int nearCity(int A); //the same as above, redundant
    
}

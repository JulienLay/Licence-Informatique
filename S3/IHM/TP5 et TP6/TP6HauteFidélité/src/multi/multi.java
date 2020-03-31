/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package multi;

import tp6hautefidélité.Fenêtre_filtrée;
import tp6hautefidélité.Fenêtre_produit;
/**
 *
 * @author julie
 */
public class multi {
    static Fenêtre_filtrée fenetre_filtrée = new Fenêtre_filtrée();
    static Fenêtre_produit fenetre_produit = new Fenêtre_produit();
    
   /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Fenetre1.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Fenetre1.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Fenetre1.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Fenetre1.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(() -> {
            fenetre_filtrée.setVisible(true);
        });
    }
    
    public static void ouvrirFenetre1(){
        java.awt.EventQueue.invokeLater(() -> {
            fenetre_filtrée.setVisible(true);
        });
    }
    
    public static void ouvrirFenetre2(){
        java.awt.EventQueue.invokeLater(() -> {
            fenetre_produit.setVisible(true);
        });
    }
    
    public static void fermerFenetre1(){
        java.awt.EventQueue.invokeLater(() -> {
            fenetre_filtrée.setVisible(false);
        });
    }
    
    public static void fermerFenetre2(){
        java.awt.EventQueue.invokeLater(() -> {
            fenetre_produit.setVisible(false);
        });
    }
    
}


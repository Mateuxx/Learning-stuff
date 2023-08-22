package br.edu.icomp.ufam.lab_heranca;

public class Circulo extends FormaGeometrica {
    private double raio;

    public Circulo(int posX, int posY, double raio) {
        super(posX, posY);
        this.raio = raio;
    }

    @Override
    public double getArea() {
        return Math.PI * raio * raio;
    }

    @Override
    public double getPerimetro() {
        return 2 * Math.PI * raio;
    }

    @Override
    public String toString() {
        return "Círculo na posição (" + getPobr/edu/icomp/ufam/lab_heranca/Circulo.java:23: error: cannot find symbol
        return "Círculo na posição (" + getPosX() + ", " + getPosY() + ") com raio de " + raio + "cm " +
                                        ^
  symbol:   method getPosX()
  location: class Circulo
br/edu/icomp/ufam/lab_heranca/Circulo.java:23: error: cannot find symbol
        return "Círculo na posição (" + getPosX() + ", " + getPosY() + ") com raio de " + raio + "cm " +
                                                           ^
  symbol:   method getPosY()
  location: class Circulo
2 errorssX() + ", " + getPosY() + ") com raio de " + raio + "cm " +
                "(área=" + getArea() + "cm², perímetro=" + getPerimetro() + "cm)";
    }
}

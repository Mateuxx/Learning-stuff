package br.edu.ufam.icomp.lab_excecoes; 

public class Coordenada {
    private int posX;
    private int posY;
    private int digito;

    public Coordenada(int posX, int posY, int digito) throws CoordenadaNegativaException, CoordenadaForaDosLimitesException, DigitoInvalidoException {
        if (posX < 0 || posY < 0) {
            throw new CoordenadaNegativaException();
        }

        if (posX < 0 || posX > 30000 || posY < 0 || posY > 30000) {
            throw new CoordenadaForaDosLimitesException();
        }

        if (digito < 0 || digito > 9) {
            throw new DigitoInvalidoException();
        }

        int ok = posX + posY;
        ok %= 10;
        if (ok != digito) {
            throw new DigitoInvalidoException();
        }

        this.posX = posX;
        this.posY = posY;
        this.digito = digito;
    }

    public double distancia(Coordenada coordenada) {
        int deltaX = coordenada.posX - this.posX;
        int deltaY = coordenada.posY - this.posY;
        return Math.sqrt(deltaX * deltaX + deltaY * deltaY);
    }

    public int getPosX() {
        return posX;
    }

    public int getPosY() {
        return posY;
    }

    @Override
    public String toString() {
        return posX + ", " + posY;
    }
}

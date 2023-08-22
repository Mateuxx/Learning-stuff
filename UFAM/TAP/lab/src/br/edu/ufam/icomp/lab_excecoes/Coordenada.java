package br.edu.ufam.icomp.lab_excecoes;

public class Coordenada {
	
    private int posX;
    private int posY;
    private int digito;

    public Coordenada(int posX, int posY, int digito) throws CoordenadaNegativaException, CoordenadaForaDosLimitesException, DigitoInvalidoException{
        try {
            if (posX < 0 || posY < 0) {
                throw new CoordenadaNegativaException();
            }

            if (posX < 0 || posY < 0 || posX > 30000 || posY > 30000) {
                throw new CoordenadaForaDosLimitesException();
            }

            int soma = posX + posY;
            int resto = soma % 10;

            if (resto != digito || digito < 0 || digito > 9) {
                throw new DigitoInvalidoException();
            }

            this.posX = posX;
            this.posY = posY;
            this.digito = digito;
        } catch (CoordenadaNegativaException e) {
            System.out.println("Exceção CoordenadaNegativaException: ");
        	}
    }

    public int getPosX() {
        return posX;
    }

    public int getPosY() {
        return posY;
    }

    public double distancia(Coordenada coordenada) {
        int diffX = coordenada.posX - posX;
        int diffY = coordenada.posY - posY;

        return Math.sqrt(diffX * diffX + diffY * diffY);
    }

    @Override
    public String toString() {
        return posX + ", " + posY;
    }
}

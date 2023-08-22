package br.edu.ufam.icomp.lab_excecoes;

public class CoordenadaNegativaException extends RoverCoordenadaException {
	private static final long serialVersionUID = 1L;

	public CoordenadaNegativaException () {
		super ("Coordenada com valor negativo");
	}
	
	public CoordenadaNegativaException (String message) {
		super(message);
	}
}

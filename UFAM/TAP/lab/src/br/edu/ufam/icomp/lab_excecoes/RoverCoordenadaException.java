package br.edu.ufam.icomp.lab_excecoes;

public class RoverCoordenadaException extends RoverException{
	private static final long serialVersionUID = 1L;

	public RoverCoordenadaException () {
		super ("Exceção geral de coordenada do rover");
	}
	
	public RoverCoordenadaException (String message) {
		super(message);
	}
}

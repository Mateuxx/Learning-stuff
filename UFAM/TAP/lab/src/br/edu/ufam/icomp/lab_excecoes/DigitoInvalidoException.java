package br.edu.ufam.icomp.lab_excecoes;

public class DigitoInvalidoException extends RoverCoordenadaException{
	private static final long serialVersionUID = 1L;

	public DigitoInvalidoException () {
		super ("Digito da coordenada inválido");
	}
	
	public DigitoInvalidoException (String message) {
		super(message);
	}
}

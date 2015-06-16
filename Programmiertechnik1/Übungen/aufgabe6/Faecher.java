// Faecher.java

package aufgabe6;

public class Faecher {

	private final static String[] FAECHER = { "Digitaltechnik",
			"Mathematik 1 und Konsoldierung", "Programmiertechnik 1",
			"Kommunikationskompetenz", "Softwaremodellierung" };

	public Faecher() {
	}

	public static boolean istZulaessig(String fach) {
		for (int i = 0; i < FAECHER.length; ++i) {
			if (FAECHER[i].equals(fach)) {
				return true;
			}
		}
		return false;

	}

}

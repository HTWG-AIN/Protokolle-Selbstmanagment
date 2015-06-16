package aufgabe6;

import aufgabe4.*;

public class BenoteteLeistung extends FachNote {
	private final String note;

	public BenoteteLeistung(String f, String note) {
		super(f);
		this.note = note;
	}

	@Override
	public boolean istBestanden() {
		try {
			if (HtwgNoten.istZulaessig(note)) {
				double n = HtwgNoten.doubleNote(note);
				if (HtwgNoten.istBestanden(n)) {
					if (n == 1.0 || n == 1.3 || n == 1.5) {
						System.out.println("sehr gut");
					}
					if (n == 1.7 || n == 2.0 || n == 2.3 || n == 2.5) {
						System.out.println("gut");
					}
					if (n == 2.7 || n == 3.0 || n == 3.3 || n == 3.5) {
						System.out.println("befriedigend");
					}
					if (n == 3.7 || n == 4.0) {
						System.out.println("ausreichend");
					}
					return true;
				} else {
					System.out.println("nicht bestaden");
				}

			}

		} catch (java.lang.IllegalArgumentException x) {
			System.out
					.println("Unzulaessige Note " + note + " wird ignoriert!");
		}
		return false;
	}

	@Override
	public boolean istBenotet() {
		return true;
	}

}

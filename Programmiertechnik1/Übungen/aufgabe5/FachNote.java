package aufgabe5;

import aufgabe4.HtwgNoten;

/**
  * @author Aiham Abusaleh
  * @version 01.06.2015
  */
public final class FachNote {

    /**
    * @param neachste verweist auf die naechste note
    */
    public final FachNote naechste;
    /**
    * @param fach ist das eingegebene Fach
    */
    public final String fach;
    /**
    * @param note ist die eingegebene Note
    */
    public final String note;
    /**
     * @param naechste verweist auf die naechste note
     * @param fach ist das eingegebene Fach
     * @param note ist die eingegebene Note
     */
    public FachNote(final FachNote naechste,
                    final String fach, final String note) {
        if (!HtwgNoten.istZulaessig(note)) {
            throw new IllegalArgumentException(note);
        }
        this.naechste = naechste;
        this.fach = fach;
        this.note = note;

    }

}


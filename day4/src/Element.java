public class Element {
    private int number;
    private boolean marked = false;

    public Element(int number) {
        this.number = number;
    }

    public int getNumber() {
        return number;
    }

    public boolean isMarked() {
        return marked;
    }

    public void setMarked() {
        marked = true;
    }

    @Override
    public String toString() {
        return "Element{" +
                "number=" + number +
                ", marked=" + marked +
                '}';
    }
}

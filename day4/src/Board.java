import java.util.ArrayList;

public class Board {
    public ArrayList<Element> numberSet = new ArrayList<>();
    public void addElement(Element e) {
        numberSet.add(e);
    }

    public boolean checkRow() {
        for(int i = 0; i < 21; i += 5) {
            if(isMarked(i) && isMarked(i + 1) && isMarked(i + 2)
                    && isMarked(i + 3) && isMarked(i + 4)) return true;
        }
        return false;
    }

    public boolean checkColumn() {
        for(int i = 0; i < 5; i++) {
            if(isMarked(i) && isMarked(i + 5) && isMarked(i + 10) && isMarked(i + 15)
                    && isMarked(i + 20)) return true;
        }
        return false;
    }
    public void markNumber(int number) {
        for (Element element : numberSet) {
            if(element.getNumber() == number) element.setMarked();
        }
    }
    public boolean isMarked(int i) {
        return numberSet.get(i).isMarked();
    }

    public int sum()  {
        return numberSet.stream().filter(el -> !el.isMarked()).mapToInt(el -> el.getNumber()).sum();
    }
}

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;

public class Main {
    public static void main(String[] args) {
        ArrayList<Integer> numbersList = readNumbers();
        ArrayList<Board> boards = readBoards();
        System.out.println(boards.size());
       for(Integer i : numbersList) {
            for(int n = boards.size() - 1; n >= 0; n--) {
                Board board = boards.get(n);
                board.markNumber(i);
                if(board.checkRow() || board.checkColumn()) {
                    System.out.println("Won with" + board.sum() * i);
                    boards.remove(board);
                    //System.exit(0);
                }
            }
        }


    }

    public static ArrayList<Integer> readNumbers() {
        ArrayList<Integer> list = new ArrayList<>();
        try {
            BufferedReader buff  = new BufferedReader(new FileReader("input"));
            String line;
            boolean first = false;
            while((line = buff.readLine()) != null) {
                if(!first) {
                    first = true;
                    String[] s = line.split(",");
                    for (String n : s) {
                        list.add(Integer.parseInt(n));
                    }
                }
            }
        } catch (Exception e) {
            System.err.println(e.toString());
        }
        return list;
    }

    public static ArrayList<Board> readBoards() {
        ArrayList<Board> list = new ArrayList<>();
        try {
            BufferedReader buff = new BufferedReader(new FileReader("input"));
            String line;
            int index = 0;
            Board board = new Board();
            while((line = buff.readLine()) != null) {
                if(index > 1) {
                    if(line.equals("")) {
                        list.add(board);
                        board = new Board();
                    }
                    else {
                        String[] s = line.split(" ");
                        for (String n : s) {
                            if (!n.equals("")) board.addElement(new Element(Integer.parseInt(n)));
                        }
                    }
                }
                index++;
            }
            list.add(board);
        } catch (Exception e) {
            System.err.println(e.toString());
        }
        return list;
    }

}

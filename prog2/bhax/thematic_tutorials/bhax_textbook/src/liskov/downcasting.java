class Base {
    public void basePrint() {
        System.out.println("base class");
    }
}
class Derived extends Base {
    public void  derivedPrint() {
        System.out.println("derived class");
    }
}

public class downcasting {

    public static void main(String[] args) {
        Derived dClass = new Derived();
        dClass.basePrint();
        dClass.derivedPrint();
        ((Base)dClass).basePrint();
        //((Base)dClass).derivedPrint(); //downcast esetén itt hibát kapunk
    }
}

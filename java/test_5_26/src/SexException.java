public class SexException extends Exception{
    String sexException;

    public SexException(){

    }

    public SexException(String sexException){
        this.sexException=sexException;
    }

    public String getMessage(){
        return this.sexException;
    }

}

public class AgeException extends Exception{ ;
    String ageException;
    public AgeException(){

    }

    public AgeException(String ageException){
        this.ageException=ageException;
    }

    public String getMessage(){
        return this.ageException;
    }

}


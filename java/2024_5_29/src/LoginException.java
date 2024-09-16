public class LoginException extends Exception{
   String loginException;
    public LoginException(){

    }

    public LoginException(String loginException){
        this.loginException=loginException;
    }

    public String getMessage(){
        return this.loginException;
    }
}

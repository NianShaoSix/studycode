module org.example.refreshcardsfx {
    requires javafx.controls;
    requires javafx.fxml;


    opens org.example.refreshcardsfx to javafx.fxml;
    exports org.example.refreshcardsfx;
}
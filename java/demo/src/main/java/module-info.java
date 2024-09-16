module org.example.demo {
    requires javafx.controls;
    requires javafx.fxml;
    requires javafx.graphics;


    opens org.example.demo to javafx.fxml;
    exports org.example.demo;
}
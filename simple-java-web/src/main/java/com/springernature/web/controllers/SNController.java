package com.springernature.web.controllers;


import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/sn")
@Slf4j
public class SNController {

  @Value("${token}")
  private String token;

  @Value("${api-key}")
  private String apiKey;

  @GetMapping("/hello")
  public String sayHello() {
    return "Hello Java Code Geeks!".concat(token).concat("-----****---").concat(apiKey);
  }
}

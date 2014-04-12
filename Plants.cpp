/* Plants
 *
 */


#include "Models.h"

void DrawFlower1(){

  static int flower1Index;

      CurrentMesh = 62; //small sphere arbitrary center
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
          ModelTrans.pushMatrix();
          ModelTrans.rotate( cos(Accumulator) * (-10.0), vec3(1, 0, 0));
          ModelTrans.translate(vec3(10.5, 1, -2));
          ModelTrans.rotate( 270, vec3(0, 1, 0));

            if(flag == 0){
              flower1Index = centers.size();
              centers.push_back(ModelTrans.getMatrix()*vec4(0, 0, 0, 1));
          }
          SetModel();
          safe_glEnableVertexAttribArray(h_aPosition);
          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
          safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
          safe_glEnableVertexAttribArray(h_aNormal);
          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
          safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
          glUniform3f(h_uColor, 0.0, 0.0, 0.0);
          safe_glUniform1f(h_uMaterial, 0.5);
          glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);

                /* leaf ellipse */
              for(int g = 1; g<7; g++){
                  CurrentMesh = 25;
                  safe_glEnableVertexAttribArray(h_aPosition);
                  safe_glEnableVertexAttribArray(h_aNormal); 
                  ModelTrans.pushMatrix();
                  
                  if(g == 1){
                    ModelTrans.rotate(80, vec3(0, 0, 1));
                  }else if (g ==2){
                    ModelTrans.translate(vec3(0, 0.2, 0));
                    ModelTrans.rotate(95, vec3(0, 0, 1));
                  }else if (g ==3){
                    ModelTrans.translate(vec3(-0.7, 0.2, 0.0));
                    ModelTrans.rotate(85, vec3(0, 0, 1));
                  }else if (g ==4){
                    ModelTrans.translate(vec3(-0.7, 0, 0.0));
                    ModelTrans.rotate(105, vec3(0, 0, 1));
                  }else if (g ==5){
                    ModelTrans.translate(vec3(-0.5, -0.1, 0));
                    ModelTrans.rotate(140, vec3(0, 0, 1));
                  }else if (g ==6){
                    ModelTrans.translate(vec3(-0.2, -0.1, 0.0));
                    ModelTrans.rotate(220, vec3(0, 0, 1));
                  }

                  SetModel();
                  safe_glEnableVertexAttribArray(h_aPosition);
                  glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                  safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                    safe_glEnableVertexAttribArray(h_aNormal);
                  glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                  safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                  glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                  safe_glUniform1f(h_uMaterial, 0.5);
                  glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                  ModelTrans.popMatrix();
              }
                    /* white leaf ellipse */
                    for(int y = 1; y<7; y++){
                        CurrentMesh = 26;
                        safe_glEnableVertexAttribArray(h_aPosition);
                        safe_glEnableVertexAttribArray(h_aNormal); 
                        ModelTrans.pushMatrix();
                        
                        if(y == 1){
                          ModelTrans.translate(vec3(0, 0, 0.1));
                          ModelTrans.rotate(80, vec3(0, 0, 1));
                        }else if (y ==2){
                          ModelTrans.translate(vec3(0, 0.2, 0.1));
                          ModelTrans.rotate(95, vec3(0, 0, 1));
                        }else if (y ==3){
                          ModelTrans.translate(vec3(-0.7, 0.2, 0.1));
                          ModelTrans.rotate(85, vec3(0, 0, 1));
                        }else if (y ==4){
                          ModelTrans.translate(vec3(-0.7, 0, 0.1));
                          ModelTrans.rotate(105, vec3(0, 0, 1));
                        }else if (y ==5){
                          ModelTrans.translate(vec3(-0.5, -0.1, 0.1));
                          ModelTrans.rotate(140, vec3(0, 0, 1));
                        }else if (y ==6){
                          ModelTrans.translate(vec3(-0.2, -0.1, 0.1));
                          ModelTrans.rotate(220, vec3(0, 0, 1));
                        }

                        SetModel();
                        safe_glEnableVertexAttribArray(h_aPosition);
                        glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                        safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                          safe_glEnableVertexAttribArray(h_aNormal);
                        glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                        safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                        glUniform3f(h_uColor, changeColor[flower1Index].x, changeColor[flower1Index].y, changeColor[flower1Index].z);
                        safe_glUniform1f(h_uMaterial, 0.5);
                        glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                        ModelTrans.popMatrix();
                    }

                          /*  pistols */
                          for(int c = 1; c<4; c++){
                              CurrentMesh = 63;
                              safe_glEnableVertexAttribArray(h_aPosition);
                              safe_glEnableVertexAttribArray(h_aNormal); 
                              ModelTrans.pushMatrix();
                              
                              if(c == 1){
                                ModelTrans.translate(vec3(-0.35, 0.75, 0));
                                ModelTrans.rotate(180, vec3(0, 0, 1));
                              }else if (c ==2){
                                ModelTrans.translate(vec3(-0.45, 0.75, 0));
                                ModelTrans.rotate(190, vec3(0, 0, 1));
                              }else if (c ==3){
                                ModelTrans.translate(vec3(-0.225, 0.75, 0.0));
                                ModelTrans.rotate(170, vec3(0, 0, 1));
                              }

                              SetModel();
                              safe_glEnableVertexAttribArray(h_aPosition);
                              glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                              safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                safe_glEnableVertexAttribArray(h_aNormal);
                              glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                              safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                              glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                              glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                              safe_glUniform1f(h_uMaterial, 0.5);
                              glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                              ModelTrans.popMatrix();
                          }
                                /*  pollen */
                                for(int c = 1; c<4; c++){
                                    CurrentMesh = 30;
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    safe_glEnableVertexAttribArray(h_aNormal); 
                                    ModelTrans.pushMatrix();
                                    
                                    if(c == 1){
                                      ModelTrans.translate(vec3(-0.35, 1.2, 0));
                                      ModelTrans.rotate(180, vec3(0, 0, 1));
                                    }else if (c ==2){
                                      ModelTrans.translate(vec3(-0.53, 1.17, 0));
                                      ModelTrans.rotate(190, vec3(0, 0, 1));
                                    }else if (c ==3){
                                      ModelTrans.translate(vec3(-0.14, 1.17, 0.0));
                                      ModelTrans.rotate(170, vec3(0, 0, 1));
                                    }

                                    SetModel();
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      safe_glEnableVertexAttribArray(h_aNormal);
                                    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                    glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                                    safe_glUniform1f(h_uMaterial, 0.5);
                                    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                    ModelTrans.popMatrix();
                                }

                                      /* white pollen */
                                      for(int p = 1; p<4; p++){
                                          CurrentMesh = 31;
                                          safe_glEnableVertexAttribArray(h_aPosition);
                                          safe_glEnableVertexAttribArray(h_aNormal); 
                                          ModelTrans.pushMatrix();
                                          
                                          if(p == 1){
                                            ModelTrans.translate(vec3(-0.35, 1.2, 0.05));
                                            ModelTrans.rotate(180, vec3(0, 0, 1));
                                          }else if (p ==2){
                                            ModelTrans.translate(vec3(-0.53, 1.17, 0.05));
                                            ModelTrans.rotate(190, vec3(0, 0, 1));
                                          }else if (p ==3){
                                            ModelTrans.translate(vec3(-0.14, 1.17, 0.05));
                                            ModelTrans.rotate(170, vec3(0, 0, 1));
                                          }

                                          SetModel();
                                          safe_glEnableVertexAttribArray(h_aPosition);
                                          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                          safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                            safe_glEnableVertexAttribArray(h_aNormal);
                                          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                          safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                          glUniform3f(h_uColor, changeColor[flower1Index].x, changeColor[flower1Index].y, changeColor[flower1Index].z);
                                          safe_glUniform1f(h_uMaterial, 0.5);
                                          glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                          ModelTrans.popMatrix();
                                      }
    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);

  }



void DrawFlower3(){

  static int flower3Index;

      CurrentMesh = 62; //small sphere arbitrary center
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
          ModelTrans.pushMatrix();
          //ModelTrans.rotate( cos(Accumulator) * (-10.0), vec3(1, 0, 0));
          ModelTrans.translate(vec3(10.5, 0.2, 8));
          ModelTrans.rotate( 220, vec3(0, 1, 0));

            if(flag == 0){
              flower3Index = centers.size();
              centers.push_back(ModelTrans.getMatrix()*vec4(0, 0, 0, 1));
          }
          SetModel();
          safe_glEnableVertexAttribArray(h_aPosition);
          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
          safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
          safe_glEnableVertexAttribArray(h_aNormal);
          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
          safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
          glUniform3f(h_uColor, 0.0, 0.0, 0.0);
          safe_glUniform1f(h_uMaterial, 0.5);
          glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);

                /* leaf ellipse */
              for(int g = 1; g<7; g++){
                  CurrentMesh = 25;
                  safe_glEnableVertexAttribArray(h_aPosition);
                  safe_glEnableVertexAttribArray(h_aNormal); 
                  ModelTrans.pushMatrix();
                  
                  if(g == 1){
                    ModelTrans.rotate(80, vec3(0, 0, 1));
                  }else if (g ==2){
                    ModelTrans.translate(vec3(0, 0.2, 0));
                    ModelTrans.rotate(95, vec3(0, 0, 1));
                  }else if (g ==3){
                    ModelTrans.translate(vec3(-0.7, 0.2, 0.0));
                    ModelTrans.rotate(85, vec3(0, 0, 1));
                  }else if (g ==4){
                    ModelTrans.translate(vec3(-0.7, 0, 0.0));
                    ModelTrans.rotate(105, vec3(0, 0, 1));
                  }else if (g ==5){
                    ModelTrans.translate(vec3(-0.5, -0.1, 0));
                    ModelTrans.rotate(140, vec3(0, 0, 1));
                  }else if (g ==6){
                    ModelTrans.translate(vec3(-0.2, -0.1, 0.0));
                    ModelTrans.rotate(220, vec3(0, 0, 1));
                  }

                  SetModel();
                  safe_glEnableVertexAttribArray(h_aPosition);
                  glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                  safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                    safe_glEnableVertexAttribArray(h_aNormal);
                  glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                  safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                  glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                  safe_glUniform1f(h_uMaterial, 0.5);
                  glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                  ModelTrans.popMatrix();
              }
                    /* white leaf ellipse */
                    for(int y = 1; y<7; y++){
                        CurrentMesh = 26;
                        safe_glEnableVertexAttribArray(h_aPosition);
                        safe_glEnableVertexAttribArray(h_aNormal); 
                        ModelTrans.pushMatrix();
                        
                        if(y == 1){
                          ModelTrans.translate(vec3(0, 0, 0.1));
                          ModelTrans.rotate(80, vec3(0, 0, 1));
                        }else if (y ==2){
                          ModelTrans.translate(vec3(0, 0.2, 0.1));
                          ModelTrans.rotate(95, vec3(0, 0, 1));
                        }else if (y ==3){
                          ModelTrans.translate(vec3(-0.7, 0.2, 0.1));
                          ModelTrans.rotate(85, vec3(0, 0, 1));
                        }else if (y ==4){
                          ModelTrans.translate(vec3(-0.7, 0, 0.1));
                          ModelTrans.rotate(105, vec3(0, 0, 1));
                        }else if (y ==5){
                          ModelTrans.translate(vec3(-0.5, -0.1, 0.1));
                          ModelTrans.rotate(140, vec3(0, 0, 1));
                        }else if (y ==6){
                          ModelTrans.translate(vec3(-0.2, -0.1, 0.1));
                          ModelTrans.rotate(220, vec3(0, 0, 1));
                        }

                        SetModel();
                        safe_glEnableVertexAttribArray(h_aPosition);
                        glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                        safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                          safe_glEnableVertexAttribArray(h_aNormal);
                        glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                        safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                        glUniform3f(h_uColor, changeColor[flower3Index].x, changeColor[flower3Index].y, changeColor[flower3Index].z);
                        safe_glUniform1f(h_uMaterial, 0.5);
                        glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                        ModelTrans.popMatrix();
                    }

                          /*  pistols */
                          for(int c = 1; c<4; c++){
                              CurrentMesh = 63;
                              safe_glEnableVertexAttribArray(h_aPosition);
                              safe_glEnableVertexAttribArray(h_aNormal); 
                              ModelTrans.pushMatrix();
                              
                              if(c == 1){
                                ModelTrans.translate(vec3(-0.35, 0.75, 0));
                                ModelTrans.rotate(180, vec3(0, 0, 1));
                              }else if (c ==2){
                                ModelTrans.translate(vec3(-0.45, 0.75, 0));
                                ModelTrans.rotate(190, vec3(0, 0, 1));
                              }else if (c ==3){
                                ModelTrans.translate(vec3(-0.225, 0.75, 0.0));
                                ModelTrans.rotate(170, vec3(0, 0, 1));
                              }

                              SetModel();
                              safe_glEnableVertexAttribArray(h_aPosition);
                              glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                              safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                safe_glEnableVertexAttribArray(h_aNormal);
                              glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                              safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                              glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                              glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                              safe_glUniform1f(h_uMaterial, 0.5);
                              glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                              ModelTrans.popMatrix();
                          }
                                /*  pollen */
                                for(int c = 1; c<4; c++){
                                    CurrentMesh = 30;
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    safe_glEnableVertexAttribArray(h_aNormal); 
                                    ModelTrans.pushMatrix();
                                    
                                    if(c == 1){
                                      ModelTrans.translate(vec3(-0.35, 1.2, 0));
                                      ModelTrans.rotate(180, vec3(0, 0, 1));
                                    }else if (c ==2){
                                      ModelTrans.translate(vec3(-0.53, 1.17, 0));
                                      ModelTrans.rotate(190, vec3(0, 0, 1));
                                    }else if (c ==3){
                                      ModelTrans.translate(vec3(-0.14, 1.17, 0.0));
                                      ModelTrans.rotate(170, vec3(0, 0, 1));
                                    }

                                    SetModel();
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      safe_glEnableVertexAttribArray(h_aNormal);
                                    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                    glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                                    safe_glUniform1f(h_uMaterial, 0.5);
                                    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                    ModelTrans.popMatrix();
                                }

                                      /* white pollen */
                                      for(int p = 1; p<4; p++){
                                          CurrentMesh = 31;
                                          safe_glEnableVertexAttribArray(h_aPosition);
                                          safe_glEnableVertexAttribArray(h_aNormal); 
                                          ModelTrans.pushMatrix();
                                          
                                          if(p == 1){
                                            ModelTrans.translate(vec3(-0.35, 1.2, 0.05));
                                            ModelTrans.rotate(180, vec3(0, 0, 1));
                                          }else if (p ==2){
                                            ModelTrans.translate(vec3(-0.53, 1.17, 0.05));
                                            ModelTrans.rotate(190, vec3(0, 0, 1));
                                          }else if (p ==3){
                                            ModelTrans.translate(vec3(-0.14, 1.17, 0.05));
                                            ModelTrans.rotate(170, vec3(0, 0, 1));
                                          }

                                          SetModel();
                                          safe_glEnableVertexAttribArray(h_aPosition);
                                          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                          safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                            safe_glEnableVertexAttribArray(h_aNormal);
                                          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                          safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                          glUniform3f(h_uColor, changeColor[flower3Index].x, changeColor[flower3Index].y, changeColor[flower3Index].z);
                                          safe_glUniform1f(h_uMaterial, 0.5);
                                          glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                          ModelTrans.popMatrix();
                                      }
    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);

  }



void DrawFlower2(){

  static int flower2Index;

      CurrentMesh = 62; //small sphere arbitrary center
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
          ModelTrans.pushMatrix();
          ModelTrans.rotate( cos(Accumulator) * (-30.0), vec3(0, 0, 1));
          ModelTrans.translate(vec3(0, 0.5, -15));

            if(flag == 0){
              flower2Index = centers.size();
              centers.push_back(ModelTrans.getMatrix()*vec4(0, 0, 0, 1));
          }
          SetModel();
          safe_glEnableVertexAttribArray(h_aPosition);
          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
          safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
          safe_glEnableVertexAttribArray(h_aNormal);
          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
          safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
          glUniform3f(h_uColor, 0.0, 0.0, 0.0);
          safe_glUniform1f(h_uMaterial, 0.5);
          glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);

                /* leaf ellipse */
              for(int g = 1; g<7; g++){
                  CurrentMesh = 25;
                  safe_glEnableVertexAttribArray(h_aPosition);
                  safe_glEnableVertexAttribArray(h_aNormal); 
                  ModelTrans.pushMatrix();
                  
                  if(g == 1){
                    ModelTrans.rotate(80, vec3(0, 0, 1));
                  }else if (g ==2){
                    ModelTrans.translate(vec3(0, 0.2, 0));
                    ModelTrans.rotate(95, vec3(0, 0, 1));
                  }else if (g ==3){
                    ModelTrans.translate(vec3(-0.7, 0.2, 0.0));
                    ModelTrans.rotate(85, vec3(0, 0, 1));
                  }else if (g ==4){
                    ModelTrans.translate(vec3(-0.7, 0, 0.0));
                    ModelTrans.rotate(105, vec3(0, 0, 1));
                  }else if (g ==5){
                    ModelTrans.translate(vec3(-0.5, -0.1, 0));
                    ModelTrans.rotate(140, vec3(0, 0, 1));
                  }else if (g ==6){
                    ModelTrans.translate(vec3(-0.2, -0.1, 0.0));
                    ModelTrans.rotate(220, vec3(0, 0, 1));
                  }

                  SetModel();
                  safe_glEnableVertexAttribArray(h_aPosition);
                  glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                  safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                    safe_glEnableVertexAttribArray(h_aNormal);
                  glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                  safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                  glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                  safe_glUniform1f(h_uMaterial, 0.5);
                  glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                  ModelTrans.popMatrix();
              }
                    /* white leaf ellipse */
                    for(int y = 1; y<7; y++){
                        CurrentMesh = 26;
                        safe_glEnableVertexAttribArray(h_aPosition);
                        safe_glEnableVertexAttribArray(h_aNormal); 
                        ModelTrans.pushMatrix();
                        
                        if(y == 1){
                          ModelTrans.translate(vec3(0, 0, 0.1));
                          ModelTrans.rotate(80, vec3(0, 0, 1));
                        }else if (y ==2){
                          ModelTrans.translate(vec3(0, 0.2, 0.1));
                          ModelTrans.rotate(95, vec3(0, 0, 1));
                        }else if (y ==3){
                          ModelTrans.translate(vec3(-0.7, 0.2, 0.1));
                          ModelTrans.rotate(85, vec3(0, 0, 1));
                        }else if (y ==4){
                          ModelTrans.translate(vec3(-0.7, 0, 0.1));
                          ModelTrans.rotate(105, vec3(0, 0, 1));
                        }else if (y ==5){
                          ModelTrans.translate(vec3(-0.5, -0.1, 0.1));
                          ModelTrans.rotate(140, vec3(0, 0, 1));
                        }else if (y ==6){
                          ModelTrans.translate(vec3(-0.2, -0.1, 0.1));
                          ModelTrans.rotate(220, vec3(0, 0, 1));
                        }

                        SetModel();
                        safe_glEnableVertexAttribArray(h_aPosition);
                        glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                        safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                          safe_glEnableVertexAttribArray(h_aNormal);
                        glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                        safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                        glUniform3f(h_uColor, changeColor[flower2Index].x, changeColor[flower2Index].y, changeColor[flower2Index].z);
                        safe_glUniform1f(h_uMaterial, 0.5);
                        glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                        ModelTrans.popMatrix();
                    }

                          /*  pistols */
                          for(int c = 1; c<4; c++){
                              CurrentMesh = 63;
                              safe_glEnableVertexAttribArray(h_aPosition);
                              safe_glEnableVertexAttribArray(h_aNormal); 
                              ModelTrans.pushMatrix();
                              
                              if(c == 1){
                                ModelTrans.translate(vec3(-0.35, 0.75, 0));
                                ModelTrans.rotate(180, vec3(0, 0, 1));
                              }else if (c ==2){
                                ModelTrans.translate(vec3(-0.45, 0.75, 0));
                                ModelTrans.rotate(190, vec3(0, 0, 1));
                              }else if (c ==3){
                                ModelTrans.translate(vec3(-0.225, 0.75, 0.0));
                                ModelTrans.rotate(170, vec3(0, 0, 1));
                              }

                              SetModel();
                              safe_glEnableVertexAttribArray(h_aPosition);
                              glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                              safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                safe_glEnableVertexAttribArray(h_aNormal);
                              glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                              safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                              glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                              glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                              safe_glUniform1f(h_uMaterial, 0.5);
                              glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                              ModelTrans.popMatrix();
                          }
                                /*  pollen */
                                for(int c = 1; c<4; c++){
                                    CurrentMesh = 30;
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    safe_glEnableVertexAttribArray(h_aNormal); 
                                    ModelTrans.pushMatrix();
                                    
                                    if(c == 1){
                                      ModelTrans.translate(vec3(-0.35, 1.2, 0));
                                      ModelTrans.rotate(180, vec3(0, 0, 1));
                                    }else if (c ==2){
                                      ModelTrans.translate(vec3(-0.53, 1.17, 0));
                                      ModelTrans.rotate(190, vec3(0, 0, 1));
                                    }else if (c ==3){
                                      ModelTrans.translate(vec3(-0.14, 1.17, 0.0));
                                      ModelTrans.rotate(170, vec3(0, 0, 1));
                                    }

                                    SetModel();
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      safe_glEnableVertexAttribArray(h_aNormal);
                                    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                    glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                                    safe_glUniform1f(h_uMaterial, 0.5);
                                    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                    ModelTrans.popMatrix();
                                }

                                      /* white pollen */
                                      for(int p = 1; p<4; p++){
                                          CurrentMesh = 31;
                                          safe_glEnableVertexAttribArray(h_aPosition);
                                          safe_glEnableVertexAttribArray(h_aNormal); 
                                          ModelTrans.pushMatrix();
                                          
                                          if(p == 1){
                                            ModelTrans.translate(vec3(-0.35, 1.2, 0.05));
                                            ModelTrans.rotate(180, vec3(0, 0, 1));
                                          }else if (p ==2){
                                            ModelTrans.translate(vec3(-0.53, 1.17, 0.05));
                                            ModelTrans.rotate(190, vec3(0, 0, 1));
                                          }else if (p ==3){
                                            ModelTrans.translate(vec3(-0.14, 1.17, 0.05));
                                            ModelTrans.rotate(170, vec3(0, 0, 1));
                                          }

                                          SetModel();
                                          safe_glEnableVertexAttribArray(h_aPosition);
                                          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                          safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                            safe_glEnableVertexAttribArray(h_aNormal);
                                          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                          safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                          glUniform3f(h_uColor, changeColor[flower2Index].x, changeColor[flower2Index].y, changeColor[flower2Index].z);
                                          safe_glUniform1f(h_uMaterial, 0.5);
                                          glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                          ModelTrans.popMatrix();
                                      }
    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);

  }

void DrawFlower5(){

  static int flower5Index;

      CurrentMesh = 62; //small sphere arbitrary center
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
          ModelTrans.pushMatrix();
          //ModelTrans.rotate( cos(Accumulator) * (-10.0), vec3(1, 0, 0));
          ModelTrans.translate(vec3(10.5, 0.6, 7));
          ModelTrans.rotate( 220, vec3(0, 1, 0));

            if(flag == 0){
              flower5Index = centers.size();
              centers.push_back(ModelTrans.getMatrix()*vec4(0, 0, 0, 1));
          }
          SetModel();
          safe_glEnableVertexAttribArray(h_aPosition);
          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
          safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
          safe_glEnableVertexAttribArray(h_aNormal);
          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
          safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
          glUniform3f(h_uColor, 0.0, 0.0, 0.0);
          safe_glUniform1f(h_uMaterial, 0.5);
          glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);

                /* leaf ellipse */
              for(int g = 1; g<7; g++){
                  CurrentMesh = 25;
                  safe_glEnableVertexAttribArray(h_aPosition);
                  safe_glEnableVertexAttribArray(h_aNormal); 
                  ModelTrans.pushMatrix();
                  
                  if(g == 1){
                    ModelTrans.rotate(80, vec3(0, 0, 1));
                  }else if (g ==2){
                    ModelTrans.translate(vec3(0, 0.2, 0));
                    ModelTrans.rotate(95, vec3(0, 0, 1));
                  }else if (g ==3){
                    ModelTrans.translate(vec3(-0.7, 0.2, 0.0));
                    ModelTrans.rotate(85, vec3(0, 0, 1));
                  }else if (g ==4){
                    ModelTrans.translate(vec3(-0.7, 0, 0.0));
                    ModelTrans.rotate(105, vec3(0, 0, 1));
                  }else if (g ==5){
                    ModelTrans.translate(vec3(-0.5, -0.1, 0));
                    ModelTrans.rotate(140, vec3(0, 0, 1));
                  }else if (g ==6){
                    ModelTrans.translate(vec3(-0.2, -0.1, 0.0));
                    ModelTrans.rotate(220, vec3(0, 0, 1));
                  }

                  SetModel();
                  safe_glEnableVertexAttribArray(h_aPosition);
                  glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                  safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                    safe_glEnableVertexAttribArray(h_aNormal);
                  glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                  safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                  glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                  safe_glUniform1f(h_uMaterial, 0.5);
                  glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                  ModelTrans.popMatrix();
              }
                    /* white leaf ellipse */
                    for(int y = 1; y<7; y++){
                        CurrentMesh = 26;
                        safe_glEnableVertexAttribArray(h_aPosition);
                        safe_glEnableVertexAttribArray(h_aNormal); 
                        ModelTrans.pushMatrix();
                        
                        if(y == 1){
                          ModelTrans.translate(vec3(0, 0, 0.1));
                          ModelTrans.rotate(80, vec3(0, 0, 1));
                        }else if (y ==2){
                          ModelTrans.translate(vec3(0, 0.2, 0.1));
                          ModelTrans.rotate(95, vec3(0, 0, 1));
                        }else if (y ==3){
                          ModelTrans.translate(vec3(-0.7, 0.2, 0.1));
                          ModelTrans.rotate(85, vec3(0, 0, 1));
                        }else if (y ==4){
                          ModelTrans.translate(vec3(-0.7, 0, 0.1));
                          ModelTrans.rotate(105, vec3(0, 0, 1));
                        }else if (y ==5){
                          ModelTrans.translate(vec3(-0.5, -0.1, 0.1));
                          ModelTrans.rotate(140, vec3(0, 0, 1));
                        }else if (y ==6){
                          ModelTrans.translate(vec3(-0.2, -0.1, 0.1));
                          ModelTrans.rotate(220, vec3(0, 0, 1));
                        }

                        SetModel();
                        safe_glEnableVertexAttribArray(h_aPosition);
                        glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                        safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                          safe_glEnableVertexAttribArray(h_aNormal);
                        glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                        safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                        glUniform3f(h_uColor, changeColor[flower5Index].x, changeColor[flower5Index].y, changeColor[flower5Index].z);
                        safe_glUniform1f(h_uMaterial, 0.5);
                        glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                        ModelTrans.popMatrix();
                    }

                          /*  pistols */
                          for(int c = 1; c<4; c++){
                              CurrentMesh = 63;
                              safe_glEnableVertexAttribArray(h_aPosition);
                              safe_glEnableVertexAttribArray(h_aNormal); 
                              ModelTrans.pushMatrix();
                              
                              if(c == 1){
                                ModelTrans.translate(vec3(-0.35, 0.75, 0));
                                ModelTrans.rotate(180, vec3(0, 0, 1));
                              }else if (c ==2){
                                ModelTrans.translate(vec3(-0.45, 0.75, 0));
                                ModelTrans.rotate(190, vec3(0, 0, 1));
                              }else if (c ==3){
                                ModelTrans.translate(vec3(-0.225, 0.75, 0.0));
                                ModelTrans.rotate(170, vec3(0, 0, 1));
                              }

                              SetModel();
                              safe_glEnableVertexAttribArray(h_aPosition);
                              glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                              safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                safe_glEnableVertexAttribArray(h_aNormal);
                              glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                              safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                              glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                              glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                              safe_glUniform1f(h_uMaterial, 0.5);
                              glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                              ModelTrans.popMatrix();
                          }
                                /*  pollen */
                                for(int c = 1; c<4; c++){
                                    CurrentMesh = 30;
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    safe_glEnableVertexAttribArray(h_aNormal); 
                                    ModelTrans.pushMatrix();
                                    
                                    if(c == 1){
                                      ModelTrans.translate(vec3(-0.35, 1.2, 0));
                                      ModelTrans.rotate(180, vec3(0, 0, 1));
                                    }else if (c ==2){
                                      ModelTrans.translate(vec3(-0.53, 1.17, 0));
                                      ModelTrans.rotate(190, vec3(0, 0, 1));
                                    }else if (c ==3){
                                      ModelTrans.translate(vec3(-0.14, 1.17, 0.0));
                                      ModelTrans.rotate(170, vec3(0, 0, 1));
                                    }

                                    SetModel();
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      safe_glEnableVertexAttribArray(h_aNormal);
                                    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                    glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                                    safe_glUniform1f(h_uMaterial, 0.5);
                                    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                    ModelTrans.popMatrix();
                                }

                                      /* white pollen */
                                      for(int p = 1; p<4; p++){
                                          CurrentMesh = 31;
                                          safe_glEnableVertexAttribArray(h_aPosition);
                                          safe_glEnableVertexAttribArray(h_aNormal); 
                                          ModelTrans.pushMatrix();
                                          
                                          if(p == 1){
                                            ModelTrans.translate(vec3(-0.35, 1.2, 0.05));
                                            ModelTrans.rotate(180, vec3(0, 0, 1));
                                          }else if (p ==2){
                                            ModelTrans.translate(vec3(-0.53, 1.17, 0.05));
                                            ModelTrans.rotate(190, vec3(0, 0, 1));
                                          }else if (p ==3){
                                            ModelTrans.translate(vec3(-0.14, 1.17, 0.05));
                                            ModelTrans.rotate(170, vec3(0, 0, 1));
                                          }

                                          SetModel();
                                          safe_glEnableVertexAttribArray(h_aPosition);
                                          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                          safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                            safe_glEnableVertexAttribArray(h_aNormal);
                                          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                          safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                          glUniform3f(h_uColor, changeColor[flower5Index].x, changeColor[flower5Index].y, changeColor[flower5Index].z);
                                          safe_glUniform1f(h_uMaterial, 0.5);
                                          glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                          ModelTrans.popMatrix();
                                      }
    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);

  }



void DrawFlower6(){

  static int flower6Index;

      CurrentMesh = 62; //small sphere arbitrary center
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
          ModelTrans.pushMatrix();
          //ModelTrans.rotate( cos(Accumulator) * (-10.0), vec3(1, 0, 0));
          ModelTrans.translate(vec3(10.5, 0.3, 5.7));
          ModelTrans.rotate( 220, vec3(0, 1, 0));

            if(flag == 0){
              flower6Index = centers.size();
              centers.push_back(ModelTrans.getMatrix()*vec4(0, 0, 0, 1));
          }
          SetModel();
          safe_glEnableVertexAttribArray(h_aPosition);
          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
          safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
          safe_glEnableVertexAttribArray(h_aNormal);
          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
          safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
          glUniform3f(h_uColor, 0.0, 0.0, 0.0);
          safe_glUniform1f(h_uMaterial, 0.5);
          glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);

                /* leaf ellipse */
              for(int g = 1; g<7; g++){
                  CurrentMesh = 25;
                  safe_glEnableVertexAttribArray(h_aPosition);
                  safe_glEnableVertexAttribArray(h_aNormal); 
                  ModelTrans.pushMatrix();
                  
                  if(g == 1){
                    ModelTrans.rotate(80, vec3(0, 0, 1));
                  }else if (g ==2){
                    ModelTrans.translate(vec3(0, 0.2, 0));
                    ModelTrans.rotate(95, vec3(0, 0, 1));
                  }else if (g ==3){
                    ModelTrans.translate(vec3(-0.7, 0.2, 0.0));
                    ModelTrans.rotate(85, vec3(0, 0, 1));
                  }else if (g ==4){
                    ModelTrans.translate(vec3(-0.7, 0, 0.0));
                    ModelTrans.rotate(105, vec3(0, 0, 1));
                  }else if (g ==5){
                    ModelTrans.translate(vec3(-0.5, -0.1, 0));
                    ModelTrans.rotate(140, vec3(0, 0, 1));
                  }else if (g ==6){
                    ModelTrans.translate(vec3(-0.2, -0.1, 0.0));
                    ModelTrans.rotate(220, vec3(0, 0, 1));
                  }

                  SetModel();
                  safe_glEnableVertexAttribArray(h_aPosition);
                  glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                  safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                    safe_glEnableVertexAttribArray(h_aNormal);
                  glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                  safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                  glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                  safe_glUniform1f(h_uMaterial, 0.5);
                  glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                  ModelTrans.popMatrix();
              }
                    /* white leaf ellipse */
                    for(int y = 1; y<7; y++){
                        CurrentMesh = 26;
                        safe_glEnableVertexAttribArray(h_aPosition);
                        safe_glEnableVertexAttribArray(h_aNormal); 
                        ModelTrans.pushMatrix();
                        
                        if(y == 1){
                          ModelTrans.translate(vec3(0, 0, 0.1));
                          ModelTrans.rotate(80, vec3(0, 0, 1));
                        }else if (y ==2){
                          ModelTrans.translate(vec3(0, 0.2, 0.1));
                          ModelTrans.rotate(95, vec3(0, 0, 1));
                        }else if (y ==3){
                          ModelTrans.translate(vec3(-0.7, 0.2, 0.1));
                          ModelTrans.rotate(85, vec3(0, 0, 1));
                        }else if (y ==4){
                          ModelTrans.translate(vec3(-0.7, 0, 0.1));
                          ModelTrans.rotate(105, vec3(0, 0, 1));
                        }else if (y ==5){
                          ModelTrans.translate(vec3(-0.5, -0.1, 0.1));
                          ModelTrans.rotate(140, vec3(0, 0, 1));
                        }else if (y ==6){
                          ModelTrans.translate(vec3(-0.2, -0.1, 0.1));
                          ModelTrans.rotate(220, vec3(0, 0, 1));
                        }

                        SetModel();
                        safe_glEnableVertexAttribArray(h_aPosition);
                        glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                        safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                          safe_glEnableVertexAttribArray(h_aNormal);
                        glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                        safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                        glUniform3f(h_uColor, changeColor[flower6Index].x, changeColor[flower6Index].y, changeColor[flower6Index].z);
                        safe_glUniform1f(h_uMaterial, 0.5);
                        glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                        ModelTrans.popMatrix();
                    }

                          /*  pistols */
                          for(int c = 1; c<4; c++){
                              CurrentMesh = 63;
                              safe_glEnableVertexAttribArray(h_aPosition);
                              safe_glEnableVertexAttribArray(h_aNormal); 
                              ModelTrans.pushMatrix();
                              
                              if(c == 1){
                                ModelTrans.translate(vec3(-0.35, 0.75, 0));
                                ModelTrans.rotate(180, vec3(0, 0, 1));
                              }else if (c ==2){
                                ModelTrans.translate(vec3(-0.45, 0.75, 0));
                                ModelTrans.rotate(190, vec3(0, 0, 1));
                              }else if (c ==3){
                                ModelTrans.translate(vec3(-0.225, 0.75, 0.0));
                                ModelTrans.rotate(170, vec3(0, 0, 1));
                              }

                              SetModel();
                              safe_glEnableVertexAttribArray(h_aPosition);
                              glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                              safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                safe_glEnableVertexAttribArray(h_aNormal);
                              glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                              safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                              glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                              glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                              safe_glUniform1f(h_uMaterial, 0.5);
                              glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                              ModelTrans.popMatrix();
                          }
                                /*  pollen */
                                for(int c = 1; c<4; c++){
                                    CurrentMesh = 30;
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    safe_glEnableVertexAttribArray(h_aNormal); 
                                    ModelTrans.pushMatrix();
                                    
                                    if(c == 1){
                                      ModelTrans.translate(vec3(-0.35, 1.2, 0));
                                      ModelTrans.rotate(180, vec3(0, 0, 1));
                                    }else if (c ==2){
                                      ModelTrans.translate(vec3(-0.53, 1.17, 0));
                                      ModelTrans.rotate(190, vec3(0, 0, 1));
                                    }else if (c ==3){
                                      ModelTrans.translate(vec3(-0.14, 1.17, 0.0));
                                      ModelTrans.rotate(170, vec3(0, 0, 1));
                                    }

                                    SetModel();
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      safe_glEnableVertexAttribArray(h_aNormal);
                                    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                    glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                                    safe_glUniform1f(h_uMaterial, 0.5);
                                    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                    ModelTrans.popMatrix();
                                }

                                      /* white pollen */
                                      for(int p = 1; p<4; p++){
                                          CurrentMesh = 31;
                                          safe_glEnableVertexAttribArray(h_aPosition);
                                          safe_glEnableVertexAttribArray(h_aNormal); 
                                          ModelTrans.pushMatrix();
                                          
                                          if(p == 1){
                                            ModelTrans.translate(vec3(-0.35, 1.2, 0.05));
                                            ModelTrans.rotate(180, vec3(0, 0, 1));
                                          }else if (p ==2){
                                            ModelTrans.translate(vec3(-0.53, 1.17, 0.05));
                                            ModelTrans.rotate(190, vec3(0, 0, 1));
                                          }else if (p ==3){
                                            ModelTrans.translate(vec3(-0.14, 1.17, 0.05));
                                            ModelTrans.rotate(170, vec3(0, 0, 1));
                                          }

                                          SetModel();
                                          safe_glEnableVertexAttribArray(h_aPosition);
                                          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                          safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                            safe_glEnableVertexAttribArray(h_aNormal);
                                          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                          safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                          glUniform3f(h_uColor, changeColor[flower6Index].x, changeColor[flower6Index].y, changeColor[flower6Index].z);
                                          safe_glUniform1f(h_uMaterial, 0.5);
                                          glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                          ModelTrans.popMatrix();
                                      }
    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);

  }


  void DrawFlower7(){

  static int flower7Index;

      CurrentMesh = 62; //small sphere arbitrary center
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
          ModelTrans.pushMatrix();
          //ModelTrans.rotate( cos(Accumulator) * (-10.0), vec3(1, 0, 0));
          ModelTrans.translate(vec3(-10.5, 0.3, 5.7));
          ModelTrans.rotate( -220, vec3(0, 1, 0));

            if(flag == 0){
              flower7Index = centers.size();
              centers.push_back(ModelTrans.getMatrix()*vec4(0, 0, 0, 1));
          }
          SetModel();
          safe_glEnableVertexAttribArray(h_aPosition);
          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
          safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
          safe_glEnableVertexAttribArray(h_aNormal);
          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
          safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
          glUniform3f(h_uColor, 0.0, 0.0, 0.0);
          safe_glUniform1f(h_uMaterial, 0.5);
          glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);

                /* leaf ellipse */
              for(int g = 1; g<7; g++){
                  CurrentMesh = 25;
                  safe_glEnableVertexAttribArray(h_aPosition);
                  safe_glEnableVertexAttribArray(h_aNormal); 
                  ModelTrans.pushMatrix();
                  
                  if(g == 1){
                    ModelTrans.rotate(80, vec3(0, 0, 1));
                  }else if (g ==2){
                    ModelTrans.translate(vec3(0, 0.2, 0));
                    ModelTrans.rotate(95, vec3(0, 0, 1));
                  }else if (g ==3){
                    ModelTrans.translate(vec3(-0.7, 0.2, 0.0));
                    ModelTrans.rotate(85, vec3(0, 0, 1));
                  }else if (g ==4){
                    ModelTrans.translate(vec3(-0.7, 0, 0.0));
                    ModelTrans.rotate(105, vec3(0, 0, 1));
                  }else if (g ==5){
                    ModelTrans.translate(vec3(-0.5, -0.1, 0));
                    ModelTrans.rotate(140, vec3(0, 0, 1));
                  }else if (g ==6){
                    ModelTrans.translate(vec3(-0.2, -0.1, 0.0));
                    ModelTrans.rotate(220, vec3(0, 0, 1));
                  }

                  SetModel();
                  safe_glEnableVertexAttribArray(h_aPosition);
                  glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                  safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                    safe_glEnableVertexAttribArray(h_aNormal);
                  glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                  safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                  glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                  safe_glUniform1f(h_uMaterial, 0.5);
                  glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                  ModelTrans.popMatrix();
              }
                    /* white leaf ellipse */
                    for(int y = 1; y<7; y++){
                        CurrentMesh = 26;
                        safe_glEnableVertexAttribArray(h_aPosition);
                        safe_glEnableVertexAttribArray(h_aNormal); 
                        ModelTrans.pushMatrix();
                        
                        if(y == 1){
                          ModelTrans.translate(vec3(0, 0, 0.1));
                          ModelTrans.rotate(80, vec3(0, 0, 1));
                        }else if (y ==2){
                          ModelTrans.translate(vec3(0, 0.2, 0.1));
                          ModelTrans.rotate(95, vec3(0, 0, 1));
                        }else if (y ==3){
                          ModelTrans.translate(vec3(-0.7, 0.2, 0.1));
                          ModelTrans.rotate(85, vec3(0, 0, 1));
                        }else if (y ==4){
                          ModelTrans.translate(vec3(-0.7, 0, 0.1));
                          ModelTrans.rotate(105, vec3(0, 0, 1));
                        }else if (y ==5){
                          ModelTrans.translate(vec3(-0.5, -0.1, 0.1));
                          ModelTrans.rotate(140, vec3(0, 0, 1));
                        }else if (y ==6){
                          ModelTrans.translate(vec3(-0.2, -0.1, 0.1));
                          ModelTrans.rotate(220, vec3(0, 0, 1));
                        }

                        SetModel();
                        safe_glEnableVertexAttribArray(h_aPosition);
                        glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                        safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                          safe_glEnableVertexAttribArray(h_aNormal);
                        glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                        safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                        glUniform3f(h_uColor, changeColor[flower7Index].x, changeColor[flower7Index].y, changeColor[flower7Index].z);
                        safe_glUniform1f(h_uMaterial, 0.5);
                        glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                        ModelTrans.popMatrix();
                    }

                          /*  pistols */
                          for(int c = 1; c<4; c++){
                              CurrentMesh = 63;
                              safe_glEnableVertexAttribArray(h_aPosition);
                              safe_glEnableVertexAttribArray(h_aNormal); 
                              ModelTrans.pushMatrix();
                              
                              if(c == 1){
                                ModelTrans.translate(vec3(-0.35, 0.75, 0));
                                ModelTrans.rotate(180, vec3(0, 0, 1));
                              }else if (c ==2){
                                ModelTrans.translate(vec3(-0.45, 0.75, 0));
                                ModelTrans.rotate(190, vec3(0, 0, 1));
                              }else if (c ==3){
                                ModelTrans.translate(vec3(-0.225, 0.75, 0.0));
                                ModelTrans.rotate(170, vec3(0, 0, 1));
                              }

                              SetModel();
                              safe_glEnableVertexAttribArray(h_aPosition);
                              glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                              safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                safe_glEnableVertexAttribArray(h_aNormal);
                              glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                              safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                              glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                              glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                              safe_glUniform1f(h_uMaterial, 0.5);
                              glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                              ModelTrans.popMatrix();
                          }
                                /*  pollen */
                                for(int c = 1; c<4; c++){
                                    CurrentMesh = 30;
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    safe_glEnableVertexAttribArray(h_aNormal); 
                                    ModelTrans.pushMatrix();
                                    
                                    if(c == 1){
                                      ModelTrans.translate(vec3(-0.35, 1.2, 0));
                                      ModelTrans.rotate(180, vec3(0, 0, 1));
                                    }else if (c ==2){
                                      ModelTrans.translate(vec3(-0.53, 1.17, 0));
                                      ModelTrans.rotate(190, vec3(0, 0, 1));
                                    }else if (c ==3){
                                      ModelTrans.translate(vec3(-0.14, 1.17, 0.0));
                                      ModelTrans.rotate(170, vec3(0, 0, 1));
                                    }

                                    SetModel();
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      safe_glEnableVertexAttribArray(h_aNormal);
                                    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                    glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                                    safe_glUniform1f(h_uMaterial, 0.5);
                                    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                    ModelTrans.popMatrix();
                                }

                                      /* white pollen */
                                      for(int p = 1; p<4; p++){
                                          CurrentMesh = 31;
                                          safe_glEnableVertexAttribArray(h_aPosition);
                                          safe_glEnableVertexAttribArray(h_aNormal); 
                                          ModelTrans.pushMatrix();
                                          
                                          if(p == 1){
                                            ModelTrans.translate(vec3(-0.35, 1.2, 0.05));
                                            ModelTrans.rotate(180, vec3(0, 0, 1));
                                          }else if (p ==2){
                                            ModelTrans.translate(vec3(-0.53, 1.17, 0.05));
                                            ModelTrans.rotate(190, vec3(0, 0, 1));
                                          }else if (p ==3){
                                            ModelTrans.translate(vec3(-0.14, 1.17, 0.05));
                                            ModelTrans.rotate(170, vec3(0, 0, 1));
                                          }

                                          SetModel();
                                          safe_glEnableVertexAttribArray(h_aPosition);
                                          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                          safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                            safe_glEnableVertexAttribArray(h_aNormal);
                                          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                          safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                          glUniform3f(h_uColor, changeColor[flower7Index].x, changeColor[flower7Index].y, changeColor[flower7Index].z);
                                          safe_glUniform1f(h_uMaterial, 0.5);
                                          glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                          ModelTrans.popMatrix();
                                      }
    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);

  }


  void DrawFlower8(){

  static int flower8Index;

      CurrentMesh = 62; //small sphere arbitrary center
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
          ModelTrans.pushMatrix();
          //ModelTrans.rotate( cos(Accumulator) * (-10.0), vec3(1, 0, 0));
          ModelTrans.translate(vec3(-10.5, 0.3, 4));
          ModelTrans.rotate( -240, vec3(0, 1, 0));

            if(flag == 0){
              flower8Index = centers.size();
              centers.push_back(ModelTrans.getMatrix()*vec4(0, 0, 0, 1));
          }
          SetModel();
          safe_glEnableVertexAttribArray(h_aPosition);
          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
          safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
          safe_glEnableVertexAttribArray(h_aNormal);
          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
          safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
          glUniform3f(h_uColor, 0.0, 0.0, 0.0);
          safe_glUniform1f(h_uMaterial, 0.5);
          glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);

                /* leaf ellipse */
              for(int g = 1; g<7; g++){
                  CurrentMesh = 25;
                  safe_glEnableVertexAttribArray(h_aPosition);
                  safe_glEnableVertexAttribArray(h_aNormal); 
                  ModelTrans.pushMatrix();
                  
                  if(g == 1){
                    ModelTrans.rotate(80, vec3(0, 0, 1));
                  }else if (g ==2){
                    ModelTrans.translate(vec3(0, 0.2, 0));
                    ModelTrans.rotate(95, vec3(0, 0, 1));
                  }else if (g ==3){
                    ModelTrans.translate(vec3(-0.7, 0.2, 0.0));
                    ModelTrans.rotate(85, vec3(0, 0, 1));
                  }else if (g ==4){
                    ModelTrans.translate(vec3(-0.7, 0, 0.0));
                    ModelTrans.rotate(105, vec3(0, 0, 1));
                  }else if (g ==5){
                    ModelTrans.translate(vec3(-0.5, -0.1, 0));
                    ModelTrans.rotate(140, vec3(0, 0, 1));
                  }else if (g ==6){
                    ModelTrans.translate(vec3(-0.2, -0.1, 0.0));
                    ModelTrans.rotate(220, vec3(0, 0, 1));
                  }

                  SetModel();
                  safe_glEnableVertexAttribArray(h_aPosition);
                  glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                  safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                    safe_glEnableVertexAttribArray(h_aNormal);
                  glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                  safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                  glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                  safe_glUniform1f(h_uMaterial, 0.5);
                  glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                  ModelTrans.popMatrix();
              }
                    /* white leaf ellipse */
                    for(int y = 1; y<7; y++){
                        CurrentMesh = 26;
                        safe_glEnableVertexAttribArray(h_aPosition);
                        safe_glEnableVertexAttribArray(h_aNormal); 
                        ModelTrans.pushMatrix();
                        
                        if(y == 1){
                          ModelTrans.translate(vec3(0, 0, 0.1));
                          ModelTrans.rotate(80, vec3(0, 0, 1));
                        }else if (y ==2){
                          ModelTrans.translate(vec3(0, 0.2, 0.1));
                          ModelTrans.rotate(95, vec3(0, 0, 1));
                        }else if (y ==3){
                          ModelTrans.translate(vec3(-0.7, 0.2, 0.1));
                          ModelTrans.rotate(85, vec3(0, 0, 1));
                        }else if (y ==4){
                          ModelTrans.translate(vec3(-0.7, 0, 0.1));
                          ModelTrans.rotate(105, vec3(0, 0, 1));
                        }else if (y ==5){
                          ModelTrans.translate(vec3(-0.5, -0.1, 0.1));
                          ModelTrans.rotate(140, vec3(0, 0, 1));
                        }else if (y ==6){
                          ModelTrans.translate(vec3(-0.2, -0.1, 0.1));
                          ModelTrans.rotate(220, vec3(0, 0, 1));
                        }

                        SetModel();
                        safe_glEnableVertexAttribArray(h_aPosition);
                        glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                        safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                          safe_glEnableVertexAttribArray(h_aNormal);
                        glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                        safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                        glUniform3f(h_uColor, changeColor[flower8Index].x, changeColor[flower8Index].y, changeColor[flower8Index].z);
                        safe_glUniform1f(h_uMaterial, 0.5);
                        glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                        ModelTrans.popMatrix();
                    }

                          /*  pistols */
                          for(int c = 1; c<4; c++){
                              CurrentMesh = 63;
                              safe_glEnableVertexAttribArray(h_aPosition);
                              safe_glEnableVertexAttribArray(h_aNormal); 
                              ModelTrans.pushMatrix();
                              
                              if(c == 1){
                                ModelTrans.translate(vec3(-0.35, 0.75, 0));
                                ModelTrans.rotate(180, vec3(0, 0, 1));
                              }else if (c ==2){
                                ModelTrans.translate(vec3(-0.45, 0.75, 0));
                                ModelTrans.rotate(190, vec3(0, 0, 1));
                              }else if (c ==3){
                                ModelTrans.translate(vec3(-0.225, 0.75, 0.0));
                                ModelTrans.rotate(170, vec3(0, 0, 1));
                              }

                              SetModel();
                              safe_glEnableVertexAttribArray(h_aPosition);
                              glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                              safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                safe_glEnableVertexAttribArray(h_aNormal);
                              glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                              safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                              glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                              glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                              safe_glUniform1f(h_uMaterial, 0.5);
                              glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                              ModelTrans.popMatrix();
                          }
                                /*  pollen */
                                for(int c = 1; c<4; c++){
                                    CurrentMesh = 30;
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    safe_glEnableVertexAttribArray(h_aNormal); 
                                    ModelTrans.pushMatrix();
                                    
                                    if(c == 1){
                                      ModelTrans.translate(vec3(-0.35, 1.2, 0));
                                      ModelTrans.rotate(180, vec3(0, 0, 1));
                                    }else if (c ==2){
                                      ModelTrans.translate(vec3(-0.53, 1.17, 0));
                                      ModelTrans.rotate(190, vec3(0, 0, 1));
                                    }else if (c ==3){
                                      ModelTrans.translate(vec3(-0.14, 1.17, 0.0));
                                      ModelTrans.rotate(170, vec3(0, 0, 1));
                                    }

                                    SetModel();
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      safe_glEnableVertexAttribArray(h_aNormal);
                                    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                    glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                                    safe_glUniform1f(h_uMaterial, 0.5);
                                    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                    ModelTrans.popMatrix();
                                }

                                      /* white pollen */
                                      for(int p = 1; p<4; p++){
                                          CurrentMesh = 31;
                                          safe_glEnableVertexAttribArray(h_aPosition);
                                          safe_glEnableVertexAttribArray(h_aNormal); 
                                          ModelTrans.pushMatrix();
                                          
                                          if(p == 1){
                                            ModelTrans.translate(vec3(-0.35, 1.2, 0.05));
                                            ModelTrans.rotate(180, vec3(0, 0, 1));
                                          }else if (p ==2){
                                            ModelTrans.translate(vec3(-0.53, 1.17, 0.05));
                                            ModelTrans.rotate(190, vec3(0, 0, 1));
                                          }else if (p ==3){
                                            ModelTrans.translate(vec3(-0.14, 1.17, 0.05));
                                            ModelTrans.rotate(170, vec3(0, 0, 1));
                                          }

                                          SetModel();
                                          safe_glEnableVertexAttribArray(h_aPosition);
                                          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                          safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                            safe_glEnableVertexAttribArray(h_aNormal);
                                          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                          safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                          glUniform3f(h_uColor, changeColor[flower8Index].x, changeColor[flower8Index].y, changeColor[flower8Index].z);
                                          safe_glUniform1f(h_uMaterial, 0.5);
                                          glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                          ModelTrans.popMatrix();
                                      }
    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);

  }



void DrawFlower4(){

  static int flower4Index;

        CurrentMesh = 62; //small sphere arbitrary center
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
          ModelTrans.pushMatrix();
          ModelTrans.rotate( cos(Accumulator) * (30.0), vec3(0, 0, 1));
          ModelTrans.translate(vec3(0, 3, -15));
            if(flag == 0){
              flower4Index = centers.size();
              centers.push_back(ModelTrans.getMatrix()*vec4(0, 0, 0, 1));
          }
          SetModel();
          safe_glEnableVertexAttribArray(h_aPosition);
          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
          safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
          safe_glEnableVertexAttribArray(h_aNormal);
          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
          safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
          glUniform3f(h_uColor, 0.0, 0.0, 0.0);
          safe_glUniform1f(h_uMaterial, 0.5);
          glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);

                  /* multiple spheres */
                for(int s = 1; s < 5; s++){
                  CurrentMesh = 30; 
                  safe_glEnableVertexAttribArray(h_aPosition);
                  safe_glEnableVertexAttribArray(h_aNormal); 
                    ModelTrans.pushMatrix();
                    
                    if(s == 1){
                      ModelTrans.rotate( 90, vec3(0, 0, 1));
                      ModelTrans.translate(vec3(-0.1, 0, 0));
                    }else if(s == 2){
                      ModelTrans.rotate( 180, vec3(0, 0, 1));
                      ModelTrans.translate(vec3(-0.1, 0, 0));
                    }else if(s == 3){
                      ModelTrans.rotate( 270, vec3(0, 0, 1));
                      ModelTrans.translate(vec3(-0.1, 0, 0));
                    }else if(s == 4){
                      ModelTrans.translate(vec3(-0.1, 0, 0));
                    }
                    SetModel();
                    safe_glEnableVertexAttribArray(h_aPosition);
                    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                    safe_glEnableVertexAttribArray(h_aNormal);
                    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                    glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                    safe_glUniform1f(h_uMaterial, 0.5);
                    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                    ModelTrans.popMatrix();
                }

                      /* petal ellipse */
                      for(int g = 1; g<14; g++){
                          CurrentMesh = 25;
                          safe_glEnableVertexAttribArray(h_aPosition);
                          safe_glEnableVertexAttribArray(h_aNormal); 
                          ModelTrans.pushMatrix();
                          
                          if(g == 1){
                            ModelTrans.translate(vec3(-.5, 0, 0));
                          }else if (g ==2){
                            ModelTrans.rotate(30, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==3){
                            ModelTrans.rotate(60, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==4){
                            ModelTrans.rotate(90, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==5){
                            ModelTrans.rotate(120, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==6){
                            ModelTrans.rotate(150, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==7){
                            ModelTrans.rotate(180, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==8){
                            ModelTrans.rotate(210, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==9){
                            ModelTrans.rotate(230, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==10){
                            ModelTrans.rotate(260, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==11){
                            ModelTrans.rotate(290, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==12){
                            ModelTrans.rotate(320, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==13){
                            ModelTrans.rotate(340, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }
                          ModelTrans.rotate(90, vec3(0, 0, 1));
                          SetModel();
                          safe_glEnableVertexAttribArray(h_aPosition);
                          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                          safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            safe_glEnableVertexAttribArray(h_aNormal);
                          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                          safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                          glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                          safe_glUniform1f(h_uMaterial, 0.5);
                          glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                          ModelTrans.popMatrix();
                      }
                              /* white petal ellipse */
                              for(int g = 1; g<14; g++){
                                  CurrentMesh = 26;
                                  safe_glEnableVertexAttribArray(h_aPosition);
                                  safe_glEnableVertexAttribArray(h_aNormal); 
                                  ModelTrans.pushMatrix();
                                  
                                  if(g == 1){
                                    ModelTrans.translate(vec3(-.5, 0, 0.1));
                                  }else if (g ==2){
                                    ModelTrans.rotate(30, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==3){
                                    ModelTrans.rotate(60, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==4){
                                    ModelTrans.rotate(90, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==5){
                                    ModelTrans.rotate(120, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==6){
                                    ModelTrans.rotate(150, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==7){
                                    ModelTrans.rotate(180, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==8){
                                    ModelTrans.rotate(210, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==9){
                                    ModelTrans.rotate(230, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==10){
                                    ModelTrans.rotate(260, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==11){
                                    ModelTrans.rotate(290, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==12){
                                    ModelTrans.rotate(320, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==13){
                                    ModelTrans.rotate(340, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }
                                  ModelTrans.rotate(90, vec3(0, 0, 1));
                                  SetModel();
                                  safe_glEnableVertexAttribArray(h_aPosition);
                                  glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                  safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                    safe_glEnableVertexAttribArray(h_aNormal);
                                  glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                  safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                  glUniform3f(h_uColor, changeColor[flower4Index].x, changeColor[flower4Index].y, changeColor[flower4Index].z);
                                  safe_glUniform1f(h_uMaterial, 0.5);
                                  glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                  ModelTrans.popMatrix();
                              }

    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);

}



void DrawFlower9(){

  static int flower9Index;

        CurrentMesh = 62; //small sphere arbitrary center
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
          ModelTrans.pushMatrix();
          ModelTrans.rotate( cos(Accumulator) * (10.0), vec3(1, 0, 0));
          ModelTrans.rotate( -10, vec3(0, 0, 1));
          ModelTrans.translate(vec3(-5, 0.5, -10));
            if(flag == 0){
              flower9Index = centers.size();
              centers.push_back(ModelTrans.getMatrix()*vec4(0, 0, 0, 1));
          }
          SetModel();
          safe_glEnableVertexAttribArray(h_aPosition);
          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
          safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
          safe_glEnableVertexAttribArray(h_aNormal);
          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
          safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
          glUniform3f(h_uColor, 0.0, 0.0, 0.0);
          safe_glUniform1f(h_uMaterial, 0.5);
          glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);

                  /* multiple spheres */
                for(int s = 1; s < 5; s++){
                  CurrentMesh = 30; 
                  safe_glEnableVertexAttribArray(h_aPosition);
                  safe_glEnableVertexAttribArray(h_aNormal); 
                    ModelTrans.pushMatrix();
                    
                    if(s == 1){
                      ModelTrans.rotate( 90, vec3(0, 0, 1));
                      ModelTrans.translate(vec3(-0.1, 0, 0));
                    }else if(s == 2){
                      ModelTrans.rotate( 180, vec3(0, 0, 1));
                      ModelTrans.translate(vec3(-0.1, 0, 0));
                    }else if(s == 3){
                      ModelTrans.rotate( 270, vec3(0, 0, 1));
                      ModelTrans.translate(vec3(-0.1, 0, 0));
                    }else if(s == 4){
                      ModelTrans.translate(vec3(-0.1, 0, 0));
                    }
                    SetModel();
                    safe_glEnableVertexAttribArray(h_aPosition);
                    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                    safe_glEnableVertexAttribArray(h_aNormal);
                    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                    glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                    safe_glUniform1f(h_uMaterial, 0.5);
                    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                    ModelTrans.popMatrix();
                }

                      /* petal ellipse */
                      for(int g = 1; g<14; g++){
                          CurrentMesh = 25;
                          safe_glEnableVertexAttribArray(h_aPosition);
                          safe_glEnableVertexAttribArray(h_aNormal); 
                          ModelTrans.pushMatrix();
                          
                          if(g == 1){
                            ModelTrans.translate(vec3(-.5, 0, 0));
                          }else if (g ==2){
                            ModelTrans.rotate(30, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==3){
                            ModelTrans.rotate(60, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==4){
                            ModelTrans.rotate(90, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==5){
                            ModelTrans.rotate(120, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==6){
                            ModelTrans.rotate(150, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==7){
                            ModelTrans.rotate(180, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==8){
                            ModelTrans.rotate(210, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==9){
                            ModelTrans.rotate(230, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==10){
                            ModelTrans.rotate(260, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==11){
                            ModelTrans.rotate(290, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==12){
                            ModelTrans.rotate(320, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==13){
                            ModelTrans.rotate(340, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }
                          ModelTrans.rotate(90, vec3(0, 0, 1));
                          SetModel();
                          safe_glEnableVertexAttribArray(h_aPosition);
                          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                          safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            safe_glEnableVertexAttribArray(h_aNormal);
                          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                          safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                          glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                          safe_glUniform1f(h_uMaterial, 0.5);
                          glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                          ModelTrans.popMatrix();
                      }
                              /* white petal ellipse */
                              for(int g = 1; g<14; g++){
                                  CurrentMesh = 26;
                                  safe_glEnableVertexAttribArray(h_aPosition);
                                  safe_glEnableVertexAttribArray(h_aNormal); 
                                  ModelTrans.pushMatrix();
                                  
                                  if(g == 1){
                                    ModelTrans.translate(vec3(-.5, 0, 0.1));
                                  }else if (g ==2){
                                    ModelTrans.rotate(30, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==3){
                                    ModelTrans.rotate(60, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==4){
                                    ModelTrans.rotate(90, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==5){
                                    ModelTrans.rotate(120, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==6){
                                    ModelTrans.rotate(150, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==7){
                                    ModelTrans.rotate(180, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==8){
                                    ModelTrans.rotate(210, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==9){
                                    ModelTrans.rotate(230, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==10){
                                    ModelTrans.rotate(260, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==11){
                                    ModelTrans.rotate(290, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==12){
                                    ModelTrans.rotate(320, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==13){
                                    ModelTrans.rotate(340, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }
                                  ModelTrans.rotate(90, vec3(0, 0, 1));
                                  SetModel();
                                  safe_glEnableVertexAttribArray(h_aPosition);
                                  glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                  safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                    safe_glEnableVertexAttribArray(h_aNormal);
                                  glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                  safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                  glUniform3f(h_uColor, changeColor[flower9Index].x, changeColor[flower9Index].y, changeColor[flower9Index].z);
                                  safe_glUniform1f(h_uMaterial, 0.5);
                                  glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                  ModelTrans.popMatrix();
                              }

    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);

}



void DrawFlower10(){

  static int flower10Index;

        CurrentMesh = 62; //small sphere arbitrary center
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
          ModelTrans.pushMatrix();
          ModelTrans.rotate( cos(Accumulator) * (5.0), vec3(1, 0, 0));
          ModelTrans.rotate( -30, vec3(0, 0, 1));
          ModelTrans.translate(vec3(-5, 0.5, -20));
            if(flag == 0){
              flower10Index = centers.size();
              centers.push_back(ModelTrans.getMatrix()*vec4(0, 0, 0, 1));
          }
          SetModel();
          safe_glEnableVertexAttribArray(h_aPosition);
          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
          safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
          safe_glEnableVertexAttribArray(h_aNormal);
          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
          safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
          glUniform3f(h_uColor, 0.0, 0.0, 0.0);
          safe_glUniform1f(h_uMaterial, 0.5);
          glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);

                  /* multiple spheres */
                for(int s = 1; s < 5; s++){
                  CurrentMesh = 30; 
                  safe_glEnableVertexAttribArray(h_aPosition);
                  safe_glEnableVertexAttribArray(h_aNormal); 
                    ModelTrans.pushMatrix();
                    
                    if(s == 1){
                      ModelTrans.rotate( 90, vec3(0, 0, 1));
                      ModelTrans.translate(vec3(-0.1, 0, 0));
                    }else if(s == 2){
                      ModelTrans.rotate( 180, vec3(0, 0, 1));
                      ModelTrans.translate(vec3(-0.1, 0, 0));
                    }else if(s == 3){
                      ModelTrans.rotate( 270, vec3(0, 0, 1));
                      ModelTrans.translate(vec3(-0.1, 0, 0));
                    }else if(s == 4){
                      ModelTrans.translate(vec3(-0.1, 0, 0));
                    }
                    SetModel();
                    safe_glEnableVertexAttribArray(h_aPosition);
                    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                    safe_glEnableVertexAttribArray(h_aNormal);
                    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                    glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                    safe_glUniform1f(h_uMaterial, 0.5);
                    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                    ModelTrans.popMatrix();
                }

                      /* petal ellipse */
                      for(int g = 1; g<14; g++){
                          CurrentMesh = 25;
                          safe_glEnableVertexAttribArray(h_aPosition);
                          safe_glEnableVertexAttribArray(h_aNormal); 
                          ModelTrans.pushMatrix();
                          
                          if(g == 1){
                            ModelTrans.translate(vec3(-.5, 0, 0));
                          }else if (g ==2){
                            ModelTrans.rotate(30, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==3){
                            ModelTrans.rotate(60, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==4){
                            ModelTrans.rotate(90, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==5){
                            ModelTrans.rotate(120, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==6){
                            ModelTrans.rotate(150, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==7){
                            ModelTrans.rotate(180, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==8){
                            ModelTrans.rotate(210, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==9){
                            ModelTrans.rotate(230, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==10){
                            ModelTrans.rotate(260, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==11){
                            ModelTrans.rotate(290, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==12){
                            ModelTrans.rotate(320, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==13){
                            ModelTrans.rotate(340, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }
                          ModelTrans.rotate(90, vec3(0, 0, 1));
                          SetModel();
                          safe_glEnableVertexAttribArray(h_aPosition);
                          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                          safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            safe_glEnableVertexAttribArray(h_aNormal);
                          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                          safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                          glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                          safe_glUniform1f(h_uMaterial, 0.5);
                          glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                          ModelTrans.popMatrix();
                      }
                              /* white petal ellipse */
                              for(int g = 1; g<14; g++){
                                  CurrentMesh = 26;
                                  safe_glEnableVertexAttribArray(h_aPosition);
                                  safe_glEnableVertexAttribArray(h_aNormal); 
                                  ModelTrans.pushMatrix();
                                  
                                  if(g == 1){
                                    ModelTrans.translate(vec3(-.5, 0, 0.1));
                                  }else if (g ==2){
                                    ModelTrans.rotate(30, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==3){
                                    ModelTrans.rotate(60, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==4){
                                    ModelTrans.rotate(90, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==5){
                                    ModelTrans.rotate(120, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==6){
                                    ModelTrans.rotate(150, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==7){
                                    ModelTrans.rotate(180, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==8){
                                    ModelTrans.rotate(210, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==9){
                                    ModelTrans.rotate(230, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==10){
                                    ModelTrans.rotate(260, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==11){
                                    ModelTrans.rotate(290, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==12){
                                    ModelTrans.rotate(320, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==13){
                                    ModelTrans.rotate(340, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }
                                  ModelTrans.rotate(90, vec3(0, 0, 1));
                                  SetModel();
                                  safe_glEnableVertexAttribArray(h_aPosition);
                                  glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                  safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                    safe_glEnableVertexAttribArray(h_aNormal);
                                  glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                  safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                  glUniform3f(h_uColor, changeColor[flower10Index].x, changeColor[flower10Index].y, changeColor[flower10Index].z);
                                  safe_glUniform1f(h_uMaterial, 0.5);
                                  glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                  ModelTrans.popMatrix();
                              }

    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);

}
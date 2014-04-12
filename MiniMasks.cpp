
#include "Models.h"

void DrawMiniMask1(){

  /* circle */
  static int miniMask1Index;
  static int miniMask2Index;
    CurrentMesh = 52;
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
        //main ellipse
        ModelTrans.pushMatrix();

          ModelTrans.rotate( cos(Accumulator) * (10.0), vec3(0, 0, 1));
          ModelTrans.rotate(22, vec3(0, 1, 0));  
          ModelTrans.translate(vec3(7, 2, 0));
          

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

              //white face ellipse   
              CurrentMesh = 53;
              safe_glEnableVertexAttribArray(h_aPosition);
              safe_glEnableVertexAttribArray(h_aNormal); 
              ModelTrans.pushMatrix();
                ModelTrans.translate(vec3(-0.09, 0, 0));
                if(flag == 0){
                  miniMask1Index = centers.size();
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
                glUniform3f(h_uColor, changeColor[miniMask1Index].x, changeColor[miniMask1Index].y, changeColor[miniMask1Index].z);
                safe_glUniform1f(h_uMaterial, 1.0);
                glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                ModelTrans.popMatrix();

                     //spheres
                      for(int y = 1; y < 8; y++){
                          CurrentMesh = 54;
                          safe_glEnableVertexAttribArray(h_aPosition);
                          safe_glEnableVertexAttribArray(h_aNormal); 
                          ModelTrans.pushMatrix();
                            if(y == 1){
                                ModelTrans.translate(vec3(-0.1, -0.1, 0));
                            }else if( y == 2){
                                ModelTrans.translate(vec3(-0.1, 0.1, -0.2));
                            }else if(y ==3){
                                ModelTrans.translate(vec3(-0.07, 0.12, -0.4));
                            }else if(y ==4){
                                ModelTrans.translate(vec3(-0.04, 0.05, -0.55));
                            }else if(y == 5){
                                ModelTrans.translate(vec3(-0.1, 0.1, 0.2));
                            }else if(y == 6){
                                ModelTrans.translate(vec3(-0.07, 0.12, 0.4));
                            }else if(y == 7){
                                ModelTrans.translate(vec3(-0.04, 0.05, 0.55));
                            }
                            //ModelTrans.rotate(-90, vec3(0, 1, 0));  
                            SetModel();
                            safe_glEnableVertexAttribArray(h_aPosition);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                            safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            safe_glEnableVertexAttribArray(h_aNormal);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                            safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                            glUniform3f(h_uColor, changeColor[miniMask1Index].x, changeColor[miniMask1Index].y, changeColor[miniMask1Index].z);
                            safe_glUniform1f(h_uMaterial, 1.0);
                            glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                            ModelTrans.popMatrix();
                      }

                                  //eye slits
                                  for(int w = 1; w<3; w++){
                                    CurrentMesh = 55;
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    safe_glEnableVertexAttribArray(h_aNormal); 
                                    ModelTrans.pushMatrix();
                                      if(w == 1){
                                        ModelTrans.translate(vec3(-0.2, -0.3, -0.3));
                                      }else if(w == 2){
                                        ModelTrans.translate(vec3(-0.2, -0.3, 0.3));
                                      }
                                      SetModel();
                                      safe_glEnableVertexAttribArray(h_aPosition);
                                      glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                      safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      safe_glEnableVertexAttribArray(h_aNormal);
                                      glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                      safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                      glUniform3f(h_uColor, changeColor[miniMask1Index].x, changeColor[miniMask1Index].y, changeColor[miniMask1Index].z);
                                      safe_glUniform1f(h_uMaterial, 1.0);
                                      glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                      ModelTrans.popMatrix();
                                  }

    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);
  }


  void DrawMiniMask2(){

  /* circle */
  static int miniMask1Index;
  static int miniMask2Index;
    CurrentMesh = 52;
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
        //main ellipse
        ModelTrans.pushMatrix();

          ModelTrans.rotate( cos(Accumulator) * (20.0), vec3(0, 0, 1));
          ModelTrans.rotate(80, vec3(0, 1, 0)); 
          ModelTrans.translate(vec3(7, 1, 0));
          //ModelTrans.rotate(-90, vec3(0, 0, 0));  

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

              //white face ellipse   
              CurrentMesh = 53;
              safe_glEnableVertexAttribArray(h_aPosition);
              safe_glEnableVertexAttribArray(h_aNormal); 
              ModelTrans.pushMatrix();
                ModelTrans.translate(vec3(-0.15, -0.05, 0));
                if(flag == 0){
                  miniMask1Index = centers.size();
                  centers.push_back(ModelTrans.getMatrix()*vec4(0, 0, 0, 1));
                }
                //ModelTrans.rotate(-90, vec3(0, 1, 0));  
                SetModel();
                safe_glEnableVertexAttribArray(h_aPosition);
                glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                safe_glEnableVertexAttribArray(h_aNormal);
                glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                glUniform3f(h_uColor, changeColor[miniMask1Index].x, changeColor[miniMask1Index].y, changeColor[miniMask1Index].z);
                //glUniform3f(h_uColor, 1.0, 1.0, 1.0);
                safe_glUniform1f(h_uMaterial, 1.0);
                glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                ModelTrans.popMatrix();

                     //spheres & eyes
                      for(int y = 1; y < 10; y++){
                          CurrentMesh = 54;
                          safe_glEnableVertexAttribArray(h_aPosition);
                          safe_glEnableVertexAttribArray(h_aNormal); 
                          ModelTrans.pushMatrix();
                            if(y == 1){
                                ModelTrans.translate(vec3(-0.1, -0.15, 0));
                            }else if( y == 2){
                                ModelTrans.translate(vec3(-0.1, -0.12, -0.2));
                            }else if(y ==3){
                                ModelTrans.translate(vec3(-0.1, -0.1, -0.4));
                            }else if(y ==4){
                                ModelTrans.translate(vec3(-0.07, -0.14, -0.55));
                            }else if(y == 5){
                                ModelTrans.translate(vec3(-0.1, -0.12, 0.2));
                            }else if(y == 6){
                                ModelTrans.translate(vec3(-0.1, -0.1, 0.4));
                            }else if(y ==7){
                                ModelTrans.translate(vec3(-0.07, -0.14, 0.55));
                            }else if(y ==8){
                                ModelTrans.translate(vec3(-0.08, -0.25, 0.35));
                            }else if(y ==9){
                                ModelTrans.translate(vec3(-0.08, -0.25, -0.35));
                            }
                            //ModelTrans.rotate(-90, vec3(0, 1, 0));  
                            SetModel();
                            safe_glEnableVertexAttribArray(h_aPosition);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                            safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            safe_glEnableVertexAttribArray(h_aNormal);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                            safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                            //glUniform3f(h_uColor, changeColor[miniMask1Index].x, changeColor[miniMask1Index].y, changeColor[miniMask1Index].z);
                            glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                            safe_glUniform1f(h_uMaterial, 1.0);
                            glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                            ModelTrans.popMatrix();
                      }

                              //black vertical line ellipse 
                              CurrentMesh = 56;
                              safe_glEnableVertexAttribArray(h_aPosition);
                              safe_glEnableVertexAttribArray(h_aNormal); 
                              ModelTrans.pushMatrix();
                                ModelTrans.translate(vec3(-0.3, 0.05, 0));
                                SetModel();
                                safe_glEnableVertexAttribArray(h_aPosition);
                                glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                safe_glEnableVertexAttribArray(h_aNormal);
                                glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                safe_glUniform1f(h_uMaterial, 1.0);
                                glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                ModelTrans.popMatrix();


                                  //mouth
                                  for(int s = 1; s<3; s++){
                                    CurrentMesh = 55;
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    safe_glEnableVertexAttribArray(h_aNormal); 
                                    ModelTrans.pushMatrix();
                                      if(s == 1){
                                        ModelTrans.translate(vec3(-0.15, -0.7, 0));
                                      }else if(s == 2){
                                        ModelTrans.translate(vec3(-0.15, -0.8, 0));
                                      }
                                      //ModelTrans.rotate(-90, vec3(0, 1, 0));  
                                      SetModel();
                                      safe_glEnableVertexAttribArray(h_aPosition);
                                      glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                      safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      safe_glEnableVertexAttribArray(h_aNormal);
                                      glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                      safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                      //glUniform3f(h_uColor, changeColor[miniMask1Index].x, changeColor[miniMask1Index].y, changeColor[miniMask1Index].z);
                                      glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                                      safe_glUniform1f(h_uMaterial, 1.0);
                                      glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                      ModelTrans.popMatrix();
                                  }



    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);
  }

  void DrawMiniMask3(){

  /* circle */
  static int miniMask1Index;
  static int miniMask2Index;
    CurrentMesh = 52;
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
        //main ellipse
        ModelTrans.pushMatrix();

          ModelTrans.rotate( cos(Accumulator) * (12.0), vec3(0, 0, 1));
          ModelTrans.rotate(-50, vec3(0, 1, 0)); 
          ModelTrans.translate(vec3(7, 2, 0));
          //ModelTrans.rotate(-90, vec3(0, 0, 0));  

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

              //white face ellipse   
              CurrentMesh = 53;
              safe_glEnableVertexAttribArray(h_aPosition);
              safe_glEnableVertexAttribArray(h_aNormal); 
              ModelTrans.pushMatrix();
                ModelTrans.translate(vec3(-0.15, -0.05, 0));
                if(flag == 0){
                  miniMask1Index = centers.size();
                  centers.push_back(ModelTrans.getMatrix()*vec4(0, 0, 0, 1));
                }
                //ModelTrans.rotate(-90, vec3(0, 1, 0));  
                SetModel();
                safe_glEnableVertexAttribArray(h_aPosition);
                glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                safe_glEnableVertexAttribArray(h_aNormal);
                glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                glUniform3f(h_uColor, changeColor[miniMask1Index].x, changeColor[miniMask1Index].y, changeColor[miniMask1Index].z);
                //glUniform3f(h_uColor, 1.0, 1.0, 1.0);
                safe_glUniform1f(h_uMaterial, 1.0);
                glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                ModelTrans.popMatrix();

                     //spheres & eyes
                      for(int y = 1; y < 5; y++){
                          CurrentMesh = 54;
                          safe_glEnableVertexAttribArray(h_aPosition);
                          safe_glEnableVertexAttribArray(h_aNormal); 
                          ModelTrans.pushMatrix();
                            if(y == 1){
                                ModelTrans.translate(vec3(-0.1, -0.1, -0.4));
                            }else if( y == 2){
                                ModelTrans.translate(vec3(-0.1, -0.1, 0.4));
                            }else if(y ==3){
                                ModelTrans.translate(vec3(-0.08, -0.4, 0.02));
                            }else if(y ==4){
                                ModelTrans.translate(vec3(-0.08, -0.4, -0.02));
                            }
                            //ModelTrans.rotate(-90, vec3(0, 1, 0));  
                            SetModel();
                            safe_glEnableVertexAttribArray(h_aPosition);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                            safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            safe_glEnableVertexAttribArray(h_aNormal);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                            safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                            //glUniform3f(h_uColor, changeColor[miniMask1Index].x, changeColor[miniMask1Index].y, changeColor[miniMask1Index].z);
                            glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                            safe_glUniform1f(h_uMaterial, 1.0);
                            glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                            ModelTrans.popMatrix();
                      }

                              //black vertical line ellipse 
                              CurrentMesh = 56;
                              safe_glEnableVertexAttribArray(h_aPosition);
                              safe_glEnableVertexAttribArray(h_aNormal); 
                              ModelTrans.pushMatrix();
                                ModelTrans.translate(vec3(-0.3, 0.05, 0));
                                SetModel();
                                safe_glEnableVertexAttribArray(h_aPosition);
                                glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                safe_glEnableVertexAttribArray(h_aNormal);
                                glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                safe_glUniform1f(h_uMaterial, 1.0);
                                glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                ModelTrans.popMatrix();


                                  //mouth
                                  for(int s = 1; s<3; s++){
                                    CurrentMesh = 55;
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    safe_glEnableVertexAttribArray(h_aNormal); 
                                    ModelTrans.pushMatrix();
                                      if(s == 1){
                                        ModelTrans.translate(vec3(-0.15, -0.7, 0));
                                      }else if(s == 2){
                                        ModelTrans.translate(vec3(-0.15, -0.8, 0));
                                      }
                                      //ModelTrans.rotate(-90, vec3(0, 1, 0));  
                                      SetModel();
                                      safe_glEnableVertexAttribArray(h_aPosition);
                                      glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                      safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      safe_glEnableVertexAttribArray(h_aNormal);
                                      glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                      safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                      //glUniform3f(h_uColor, changeColor[miniMask1Index].x, changeColor[miniMask1Index].y, changeColor[miniMask1Index].z);
                                      glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                                      safe_glUniform1f(h_uMaterial, 1.0);
                                      glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                      ModelTrans.popMatrix();
                                  }

    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);
  }


  void DrawMiniMask4(){

  /* circle */
  static int miniMask1Index;
  static int miniMask2Index;
    CurrentMesh = 52;
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
        //main ellipse
        ModelTrans.pushMatrix();

        ModelTrans.rotate( cos(Accumulator) * (5.0), vec3(0, 1, 0));
          ModelTrans.rotate(110, vec3(0, 1, 0)); 
          ModelTrans.translate(vec3(7, 1, 0));
          //ModelTrans.rotate(-90, vec3(0, 0, 0));  

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

              //white face ellipse   
              CurrentMesh = 53;
              safe_glEnableVertexAttribArray(h_aPosition);
              safe_glEnableVertexAttribArray(h_aNormal); 
              ModelTrans.pushMatrix();
                ModelTrans.translate(vec3(-0.15, -0.05, 0));
                if(flag == 0){
                  miniMask1Index = centers.size();
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
                glUniform3f(h_uColor, changeColor[miniMask1Index].x, changeColor[miniMask1Index].y, changeColor[miniMask1Index].z);
                //glUniform3f(h_uColor, 1.0, 1.0, 1.0);
                safe_glUniform1f(h_uMaterial, 1.0);
                glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                ModelTrans.popMatrix();

                     //spheres & eyes
                      for(int y = 1; y < 5; y++){
                          CurrentMesh = 54;
                          safe_glEnableVertexAttribArray(h_aPosition);
                          safe_glEnableVertexAttribArray(h_aNormal); 
                          ModelTrans.pushMatrix();
                            if(y == 1){
                                ModelTrans.translate(vec3(-0.1, 0.1, -0.35));
                            }else if( y == 2){
                                ModelTrans.translate(vec3(-0.1, 0.1, 0.35));
                            }
                            //ModelTrans.rotate(-90, vec3(0, 1, 0));  
                            SetModel();
                            safe_glEnableVertexAttribArray(h_aPosition);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                            safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            safe_glEnableVertexAttribArray(h_aNormal);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                            safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                            //glUniform3f(h_uColor, changeColor[miniMask1Index].x, changeColor[miniMask1Index].y, changeColor[miniMask1Index].z);
                            glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                            safe_glUniform1f(h_uMaterial, 1.0);
                            glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                            ModelTrans.popMatrix();
                      }
                                  //markings
                                  for(int s = 1; s<6; s++){
                                    CurrentMesh = 55;
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    safe_glEnableVertexAttribArray(h_aNormal); 
                                    ModelTrans.pushMatrix();
                                      if(s == 1){
                                        ModelTrans.translate(vec3(-0.15, 0.3, 0.32));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if( s == 2){
                                        ModelTrans.translate(vec3(-0.15, 0.3, -0.32));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 3){
                                        ModelTrans.translate(vec3(-0.15, -0.4, 0.32));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if( s == 4){
                                        ModelTrans.translate(vec3(-0.15, -0.4, -0.32));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if( s == 5){
                                        ModelTrans.translate(vec3(-0.13, -0.8, 0.));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }
                                      //ModelTrans.rotate(-90, vec3(0, 1, 0));  
                                      SetModel();
                                      safe_glEnableVertexAttribArray(h_aPosition);
                                      glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                      safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      safe_glEnableVertexAttribArray(h_aNormal);
                                      glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                      safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                      //glUniform3f(h_uColor, changeColor[miniMask1Index].x, changeColor[miniMask1Index].y, changeColor[miniMask1Index].z);
                                      glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                                      safe_glUniform1f(h_uMaterial, 1.0);
                                      glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                      ModelTrans.popMatrix();
                                  }
                                      //longer ellipse markings
                                      for(int s = 1; s<5; s++){
                                        CurrentMesh = 60;
                                        safe_glEnableVertexAttribArray(h_aPosition);
                                        safe_glEnableVertexAttribArray(h_aNormal); 
                                        ModelTrans.pushMatrix();
                                          if(s == 1){
                                            ModelTrans.translate(vec3(-0.15, 0.6, 0.0));
                                          }else if( s == 2){
                                            ModelTrans.translate(vec3(-0.19, -0.3, -0.32));
                                            ModelTrans.rotate(-5, vec3(1, 0, 0));
                                          }else if(s == 3){
                                            ModelTrans.translate(vec3(-0.19, -0.3, 0.32));
                                            ModelTrans.rotate(5, vec3(1, 0, 0));
                                          }else if (s == 4){
                                            ModelTrans.translate(vec3(-0.15, 0.3, 0.0));
                                            ModelTrans.rotate(-90, vec3(1, 0, 0));
                                          }
                                          //ModelTrans.rotate(-90, vec3(0, 1, 0));  
                                          SetModel();
                                          safe_glEnableVertexAttribArray(h_aPosition);
                                          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                          safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                          safe_glEnableVertexAttribArray(h_aNormal);
                                          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                          safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                          //glUniform3f(h_uColor, changeColor[miniMask1Index].x, changeColor[miniMask1Index].y, changeColor[miniMask1Index].z);
                                          glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                                          safe_glUniform1f(h_uMaterial, 1.0);
                                          glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                          ModelTrans.popMatrix();
                                      }
    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);
  }




  void DrawMiniMask5(){

  /* circle */
  static int miniMask5Index;
    CurrentMesh = 52;
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
        //main ellipse
        ModelTrans.pushMatrix();

          ModelTrans.rotate( cos(Accumulator) * (20.0), vec3(0, 0, 1));
          ModelTrans.rotate(140, vec3(0, 1, 0)); 
          ModelTrans.translate(vec3(10, 1, 0));
          if(flag == 0){
                  miniMask5Index = centers.size();
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

                     //spheres & eyes
                      for(int y = 1; y < 5; y++){
                          CurrentMesh = 54;
                          safe_glEnableVertexAttribArray(h_aPosition);
                          safe_glEnableVertexAttribArray(h_aNormal); 
                          ModelTrans.pushMatrix();
                            if(y == 1){
                                ModelTrans.translate(vec3(-0.1, 0.1, -0.35));
                            }else if( y == 2){
                                ModelTrans.translate(vec3(-0.1, 0.1, 0.35));
                            }
                            SetModel();
                            safe_glEnableVertexAttribArray(h_aPosition);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                            safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            safe_glEnableVertexAttribArray(h_aNormal);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                            safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                            glUniform3f(h_uColor, changeColor[miniMask5Index].x, changeColor[miniMask5Index].y, changeColor[miniMask5Index].z);
                            safe_glUniform1f(h_uMaterial, 1.0);
                            glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                            ModelTrans.popMatrix();
                      }

                                      //longer ellipse markings
                                      for(int s = 1; s<5; s++){
                                        CurrentMesh = 60;
                                        safe_glEnableVertexAttribArray(h_aPosition);
                                        safe_glEnableVertexAttribArray(h_aNormal); 
                                        ModelTrans.pushMatrix();
                                          if(s == 1){
                                            ModelTrans.translate(vec3(-0.15, 0.6, 0.0));
                                          }else if( s == 2){
                                            ModelTrans.translate(vec3(-0.19, -0.3, -0.32));
                                            ModelTrans.rotate(-5, vec3(1, 0, 0));
                                          }else if(s == 3){
                                            ModelTrans.translate(vec3(-0.19, -0.3, 0.32));
                                            ModelTrans.rotate(5, vec3(1, 0, 0));
                                          }else if (s == 4){
                                            ModelTrans.translate(vec3(-0.15, 0.3, 0.0));
                                            ModelTrans.rotate(-90, vec3(1, 0, 0));
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
                                          safe_glUniform1f(h_uMaterial, 1.0);
                                          glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                          ModelTrans.popMatrix();
                                      }

                                      //markings
                                      for(int c = 1; c<4; c++){
                                        CurrentMesh = 60;
                                        safe_glEnableVertexAttribArray(h_aPosition);
                                        safe_glEnableVertexAttribArray(h_aNormal); 
                                        ModelTrans.pushMatrix();
                                          if(c == 1){
                                            ModelTrans.translate(vec3(-0.15, 0.6, 0.0));
                                          }else if( c == 2){
                                            ModelTrans.translate(vec3(-0.19, -0.3, -0.32));
                                            ModelTrans.rotate(-5, vec3(1, 0, 0));
                                          }else if(c == 3){
                                            ModelTrans.translate(vec3(-0.19, -0.3, 0.32));
                                            ModelTrans.rotate(5, vec3(1, 0, 0));
                                          }
                                          SetModel();
                                          safe_glEnableVertexAttribArray(h_aPosition);
                                          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                          safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                          safe_glEnableVertexAttribArray(h_aNormal);
                                          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                          safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                          glUniform3f(h_uColor, changeColor[miniMask5Index].x, changeColor[miniMask5Index].y, changeColor[miniMask5Index].z);
                                          safe_glUniform1f(h_uMaterial, 1.0);
                                          glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                          ModelTrans.popMatrix();
                                      }
    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);
  }



  void DrawMiniMask6(){

  /* circle */
  static int miniMask6Index;
    CurrentMesh = 52;
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
        //main ellipse
        ModelTrans.pushMatrix();

          ModelTrans.rotate( cos(Accumulator) * (-20.0), vec3(1, 0, 0));
          ModelTrans.rotate(180, vec3(0, 1, 0)); 
          ModelTrans.translate(vec3(12, 2, 0));
          if(flag == 0){
                  miniMask6Index = centers.size();
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

                     //spheres & eyes
                      for(int y = 1; y < 5; y++){
                          CurrentMesh = 54;
                          safe_glEnableVertexAttribArray(h_aPosition);
                          safe_glEnableVertexAttribArray(h_aNormal); 
                          ModelTrans.pushMatrix();
                            if(y == 1){
                                ModelTrans.translate(vec3(-0.1, 0.1, -0.35));
                            }else if( y == 2){
                                ModelTrans.translate(vec3(-0.1, 0.1, 0.35));
                            }
                            SetModel();
                            safe_glEnableVertexAttribArray(h_aPosition);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                            safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            safe_glEnableVertexAttribArray(h_aNormal);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                            safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                            glUniform3f(h_uColor, changeColor[miniMask6Index].x, changeColor[miniMask6Index].y, changeColor[miniMask6Index].z);
                            safe_glUniform1f(h_uMaterial, 1.0);
                            glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                            ModelTrans.popMatrix();
                      }

                                      //longer ellipse markings
                                      for(int s = 1; s<5; s++){
                                        CurrentMesh = 60;
                                        safe_glEnableVertexAttribArray(h_aPosition);
                                        safe_glEnableVertexAttribArray(h_aNormal); 
                                        ModelTrans.pushMatrix();
                                          if(s == 1){
                                            ModelTrans.translate(vec3(-0.15, 0.6, 0.0));
                                          }else if( s == 2){
                                            ModelTrans.translate(vec3(-0.19, -0.3, -0.32));
                                            ModelTrans.rotate(-5, vec3(1, 0, 0));
                                          }else if(s == 3){
                                            ModelTrans.translate(vec3(-0.19, -0.3, 0.32));
                                            ModelTrans.rotate(5, vec3(1, 0, 0));
                                          }else if (s == 4){
                                            ModelTrans.translate(vec3(-0.15, 0.3, 0.0));
                                            ModelTrans.rotate(-90, vec3(1, 0, 0));
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
                                          safe_glUniform1f(h_uMaterial, 1.0);
                                          glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                          ModelTrans.popMatrix();
                                      }

                                      //3 nose
                                      for(int c = 1; c<4; c++){
                                        CurrentMesh = 63;
                                        safe_glEnableVertexAttribArray(h_aPosition);
                                        safe_glEnableVertexAttribArray(h_aNormal); 
                                        ModelTrans.pushMatrix();
                                        if(c == 1){
                                          ModelTrans.translate(vec3(-0.3, -0.3, 0));
                                          ModelTrans.rotate(180, vec3(1, 0, 0));
                                        }else if (c ==2){
                                          ModelTrans.translate(vec3(-0.3, -0.3, 0));
                                          ModelTrans.rotate(190, vec3(1, 0, 0));
                                        }else if (c ==3){

                                          ModelTrans.translate(vec3(-0.3, -0.3, 0));
                                          ModelTrans.rotate(170, vec3(1, 0, 0));
                                          
                                        }
                                          
                                          SetModel();
                                          safe_glEnableVertexAttribArray(h_aPosition);
                                          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                          safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                          safe_glEnableVertexAttribArray(h_aNormal);
                                          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                          safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                          glUniform3f(h_uColor, changeColor[miniMask6Index].x, changeColor[miniMask6Index].y, changeColor[miniMask6Index].z);
                                          safe_glUniform1f(h_uMaterial, 1.0);
                                          glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                          ModelTrans.popMatrix();
                                      }
    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);
  }




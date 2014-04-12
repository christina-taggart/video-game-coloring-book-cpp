/*
 * Masks.cpp
 */

 
#include "Models.h"
void DrawMask1(){
  static int mask1Index;
  static int mask2Index;
  CurrentMesh = 8;
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 

        //main ellipse
        ModelTrans.pushMatrix();

          ModelTrans.translate(vec3(0, 10, 25));

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
              CurrentMesh = 9;
              safe_glEnableVertexAttribArray(h_aPosition);
              safe_glEnableVertexAttribArray(h_aNormal); 

              ModelTrans.pushMatrix();

                ModelTrans.translate(vec3(0, 0, -.3));
                if(flag == 0){
                  mask1Index = centers.size();
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
                glUniform3f(h_uColor, changeColor[mask1Index].x, changeColor[mask1Index].y, changeColor[mask1Index].z);
                safe_glUniform1f(h_uMaterial, 1.0);

                glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                ModelTrans.popMatrix();
                    //eyes
                    for(int a = 1; a<3; a++){
                      CurrentMesh = 10;
                      safe_glEnableVertexAttribArray(h_aPosition);
                      safe_glEnableVertexAttribArray(h_aNormal); 

                      ModelTrans.pushMatrix();
                        
                        if(a == 1){
                          ModelTrans.translate(vec3(-1.7, 1.5, 5)); 
                        }else{
                          ModelTrans.translate(vec3(1.7, 1.5, 5)); 
                        }
                        ModelTrans.translate(vec3(0, 0, -6.5)); 
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

                          //nose
                          CurrentMesh = 7;
                          safe_glEnableVertexAttribArray(h_aPosition);
                          safe_glEnableVertexAttribArray(h_aNormal); 

                          ModelTrans.pushMatrix();
                          ModelTrans.translate(vec3(0, -.3, -.5)); 
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

                            //nose holes
                            for(int d = 1; d< 3; d++){
                              CurrentMesh = 13;
                              safe_glEnableVertexAttribArray(h_aPosition);
                              safe_glEnableVertexAttribArray(h_aNormal); 

                              ModelTrans.pushMatrix();
                              if(d == 1){
                                ModelTrans.translate(vec3(0.4, -4, -1)); 
                                ModelTrans.rotate( -5, vec3(0, 0, 1));
                              }else if(d ==2){
                                ModelTrans.translate(vec3(-0.4, -4, -1)); 
                                ModelTrans.rotate( 5, vec3(0, 0, 1));
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

                                  //bigger outer ear
                                  
                                  for(int e = 1; e< 3; e++){
                                    CurrentMesh = 1;
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    safe_glEnableVertexAttribArray(h_aNormal); 

                                    ModelTrans.pushMatrix();
                                    if(e == 1){
                                      ModelTrans.translate(vec3(5, 1.5, 0)); 
                                      ModelTrans.rotate( 3, vec3(0, 0, 1));
                                    }else if(e ==2){
                                      ModelTrans.translate(vec3(-5, 1.5, 0)); 
                                      ModelTrans.rotate( -3, vec3(0, 0, 1));
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
                                  
                                      //inner ear
                                      for(int f = 1; f< 3; f++){
                                        CurrentMesh = 13;
                                        safe_glEnableVertexAttribArray(h_aPosition);
                                        safe_glEnableVertexAttribArray(h_aNormal); 

                                        ModelTrans.pushMatrix();
                                        if(f == 1){
                                          ModelTrans.translate(vec3(5, 1.5, -0.05)); 
                                          ModelTrans.rotate( 3, vec3(0, 0, 1));
                                        }else if(f ==2){
                                          ModelTrans.translate(vec3(-5, 1.5, -0.05)); 
                                          ModelTrans.rotate( -3, vec3(0, 0, 1));
                                        }
                                        SetModel();

                                        safe_glEnableVertexAttribArray(h_aPosition);
                                        glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                        safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);

                                        safe_glEnableVertexAttribArray(h_aNormal);
                                        glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                        safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);

                                        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);

                                        glUniform3f(h_uColor, changeColor[mask1Index].x, changeColor[mask1Index].y, changeColor[mask1Index].z );
                                        safe_glUniform1f(h_uMaterial, 1.0);

                                        glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                        ModelTrans.popMatrix();
                                      }

                             for(int b = 1; b<3; b++){
                              //pupils
                              CurrentMesh = 6;
                              safe_glEnableVertexAttribArray(h_aPosition);
                              safe_glEnableVertexAttribArray(h_aNormal); 

                              ModelTrans.pushMatrix();
                                
                                if(b == 1){
                                  //ModelTrans.rotate( cos(Accumulator) * (20.0), vec3(0, 0, 1));
                                  ModelTrans.translate(vec3(-1.7, 1.1, 5.5)); 
                                  
                                }else if( b == 2){
                                  //ModelTrans.rotate( cos(Accumulator) * (20.0), vec3(0, 0, 1));
                                  ModelTrans.translate(vec3(1.7, 1.1, 5.5)); 

                                }
                                ModelTrans.translate(vec3(0, 0, -7)); 
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

                                  //feather
                                  CurrentMesh = 5;
                                  safe_glEnableVertexAttribArray(h_aPosition);
                                  safe_glEnableVertexAttribArray(h_aNormal); 

                                  ModelTrans.pushMatrix();
    
                                    ModelTrans.rotate( cos(Accumulator) * (5.0), vec3(0, 0, 1));
                                    
                                    ModelTrans.translate(vec3(0, 11, 0)); 
                                    ModelTrans.rotate( 180, vec3(0, 0, 1));
                                    
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

                                        //spheres
                                        for(int c = 1; c<5; c++){
                                          CurrentMesh = 3;
                                          safe_glEnableVertexAttribArray(h_aPosition);
                                          safe_glEnableVertexAttribArray(h_aNormal); 

                                          ModelTrans.pushMatrix();

                                            if(c ==1){
                                              ModelTrans.translate(vec3(-2.7, -6.7, -0.6)); 
                                            }else if (c == 2){
                                               ModelTrans.translate(vec3(2.7, -6.7, -0.6));  
                                            }else if (c == 3){
                                              ModelTrans.translate(vec3(-1, -7.7, -0.7)); 
                                            }else if (c == 4){
                                              ModelTrans.translate(vec3(1, -7.7, -0.7)); 
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
    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);
  }



  void DrawMask2(){
        static int mask2Index; 
        CurrentMesh = 14;
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 

        //main ellipse
        ModelTrans.pushMatrix();

          ModelTrans.rotate(-35, vec3(0, 1, 0)); 
          ModelTrans.translate(vec3(0, 10, 25)); 


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
              CurrentMesh = 15;
              safe_glEnableVertexAttribArray(h_aPosition);
              safe_glEnableVertexAttribArray(h_aNormal); 

              ModelTrans.pushMatrix();
              ModelTrans.translate(vec3(0, 0, -.3));

                if(flag == 0){
                  mask2Index = centers.size(); 
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
                glUniform3f(h_uColor, changeColor[mask2Index].x, changeColor[mask2Index].y, changeColor[mask2Index].z );
                safe_glUniform1f(h_uMaterial, 1.0);

                glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                ModelTrans.popMatrix();
                    //eyes
                    for(int a = 1; a<3; a++){
                      CurrentMesh = 16;
                      safe_glEnableVertexAttribArray(h_aPosition);
                      safe_glEnableVertexAttribArray(h_aNormal); 

                      ModelTrans.pushMatrix();
                        
                        if(a == 1){
                          ModelTrans.translate(vec3(-1.7, 1.5, 5)); 
                        }else{
                          ModelTrans.translate(vec3(1.7, 1.5, 5)); 
                        }
                        ModelTrans.translate(vec3(0, 0, -6.5)); 
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

                          //nose
                          CurrentMesh = 17;
                          safe_glEnableVertexAttribArray(h_aPosition);
                          safe_glEnableVertexAttribArray(h_aNormal); 

                          ModelTrans.pushMatrix();
                          ModelTrans.translate(vec3(0, -.3, -.5)); 
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

                            //nose holes
                            for(int d = 1; d< 3; d++){
                              CurrentMesh = 18;
                              safe_glEnableVertexAttribArray(h_aPosition);
                              safe_glEnableVertexAttribArray(h_aNormal); 

                              ModelTrans.pushMatrix();
                              if(d == 1){
                                ModelTrans.translate(vec3(0.4, -4, -1)); 
                              }else if(d ==2){
                                ModelTrans.translate(vec3(-0.4, -4, -1)); 
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
                                  //nose holes
                                  for(int d = 1; d< 3; d++){
                                    CurrentMesh = 19;
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    safe_glEnableVertexAttribArray(h_aNormal); 

                                    ModelTrans.pushMatrix();
                                    if(d == 1){
                                      ModelTrans.translate(vec3(0.4, -4.25, -1.5)); 
                                    }else if(d ==2){
                                      ModelTrans.translate(vec3(-0.4, -4.25, -1.5)); 
                                    }
                                    SetModel();

                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);

                                    safe_glEnableVertexAttribArray(h_aNormal);
                                    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);

                                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);

                                    glUniform3f(h_uColor, changeColor[mask2Index].x, changeColor[mask2Index].y, changeColor[mask2Index].z );
                                    safe_glUniform1f(h_uMaterial, 1.0);

                                    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                    ModelTrans.popMatrix();
                                  }


                                  //ears
                                  
                                  for(int e = 1; e< 3; e++){
                                    CurrentMesh = 20;
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    safe_glEnableVertexAttribArray(h_aNormal); 

                                    ModelTrans.pushMatrix();
                                    if(e == 1){
                                      ModelTrans.translate(vec3(5, 3.0, 0)); 
                                      ModelTrans.rotate( 3, vec3(0, 0, 1));
                                    }else if(e ==2){
                                      ModelTrans.translate(vec3(-5, 3.0, 0)); 
                                      ModelTrans.rotate( -3, vec3(0, 0, 1));
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
                                  

                             for(int b = 1; b<3; b++){
                              //pupils
                              CurrentMesh = 21;
                              safe_glEnableVertexAttribArray(h_aPosition);
                              safe_glEnableVertexAttribArray(h_aNormal); 

                              ModelTrans.pushMatrix();
                                
                                if(b == 1){
                                  //ModelTrans.rotate( cos(Accumulator) * (20.0), vec3(0, 0, 1));
                                  ModelTrans.translate(vec3(-1.7, 1.1, 5.5)); 
                                  
                                }else if( b == 2){
                                  //ModelTrans.rotate( cos(Accumulator) * (20.0), vec3(0, 0, 1));
                                  ModelTrans.translate(vec3(1.7, 1.1, 5.5)); 

                                }
                                ModelTrans.translate(vec3(0, 0, -7)); 
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
                                              //cubes
                                          
                                              for(int c = 1; c<15; c++){
                                                CurrentMesh = 22;
                                                safe_glEnableVertexAttribArray(h_aPosition);
                                                safe_glEnableVertexAttribArray(h_aNormal); 

                                                ModelTrans.pushMatrix();

                                                  if(c ==1){
                                                    ModelTrans.translate(vec3(-5.3, 0, 0));
                                                  }else if (c == 2){
                                                     ModelTrans.translate(vec3(-5.3, -1.5, 0)); 
                                                  }else if (c == 3){
                                                     ModelTrans.translate(vec3(-5, -3.0, 0));
                                                  }else if (c == 4){
                                                    ModelTrans.translate(vec3(-4.8, -4.5, 0));
                                                  }else if (c == 5){
                                                    ModelTrans.translate(vec3(-4.5, -6.0, 0));
                                                  }else if (c == 6){
                                                    ModelTrans.translate(vec3(-3.8, -7.5, 0));
                                                  }else if (c == 7){
                                                     ModelTrans.translate(vec3(5.3, -1.5, 0)); 
                                                  }else if (c == 8){
                                                     ModelTrans.translate(vec3(5, -3.0, 0));
                                                  }else if (c == 9){
                                                    ModelTrans.translate(vec3(4.8, -4.5, 0));
                                                  }else if (c == 10){
                                                    ModelTrans.translate(vec3(4.5, -6.0, 0));
                                                  }else if (c == 11){
                                                    ModelTrans.translate(vec3(3.8, -7.5, 0));
                                                  }else if (c == 12){
                                                    ModelTrans.translate(vec3(5.3, 0, 0));
                                                  }else if (c == 13){
                                                    ModelTrans.translate(vec3(5.3, 1.5, 0));
                                                  }else if (c == 14){
                                                    ModelTrans.translate(vec3(-5.3, 1.5, 0));
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
                                                
                              for(int b = 1; b<6; b++){
                              //dots
                              CurrentMesh = 23;
                              safe_glEnableVertexAttribArray(h_aPosition);
                              safe_glEnableVertexAttribArray(h_aNormal); 

                              ModelTrans.pushMatrix();
                                
                                if(b == 1){
                                  //ModelTrans.rotate( cos(Accumulator) * (20.0), vec3(0, 0, 1));
                                  ModelTrans.translate(vec3(-1.7, 3, 5.5)); 
                                  
                                }else if( b == 2){
                                  //ModelTrans.rotate( cos(Accumulator) * (20.0), vec3(0, 0, 1));
                                  ModelTrans.translate(vec3(1.7, 3, 5.5)); 

                                }else if(b == 3){
                                  //ModelTrans.rotate( cos(Accumulator) * (20.0), vec3(0, 0, 1));
                                  ModelTrans.translate(vec3(-2, 9.5, 5.5)); 
                                  
                                }else if( b == 4){
                                  //ModelTrans.rotate( cos(Accumulator) * (20.0), vec3(0, 0, 1));
                                  ModelTrans.translate(vec3(2, 9.5, 5.5)); 

                                }else if( b == 5){
                                  //ModelTrans.rotate( cos(Accumulator) * (20.0), vec3(0, 0, 1));
                                  ModelTrans.translate(vec3(0, 12, 5.5)); 

                                }
                                ModelTrans.translate(vec3(0, 0, -7)); 
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

                              //hat
                              for(int b = 1; b<4; b++){
                              CurrentMesh = 24;
                              safe_glEnableVertexAttribArray(h_aPosition);
                              safe_glEnableVertexAttribArray(h_aNormal); 

                              ModelTrans.pushMatrix();
                                
                                if(b == 1){

                                  ModelTrans.translate(vec3(-1.7, 11, 0)); 
                                  ModelTrans.rotate(30, vec3(1, 0, 0)); 
                                  
                                }else if( b == 2){
                                   
                                  ModelTrans.translate(vec3(1.7, 11, 0));
                                  ModelTrans.rotate(30, vec3(1, 0, 0)); 

                                }else if(b ==3){
                                  ModelTrans.translate(vec3(0, 13, 0)); 
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
    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);
  }


















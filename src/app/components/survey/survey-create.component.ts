import { Component } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { NgFor } from '@angular/common';
import { Question } from '../../models/survey.model';

@Component({
  selector: 'app-survey-create',
  standalone: true,
  imports: [FormsModule, NgFor],
  template: `
    <div class="survey-create">
      <h2>Crear Nueva Encuesta</h2>
      <form (ngSubmit)="onSubmit()" #surveyForm="ngForm">
        <div class="form-group">
          <label for="title">Título de la Encuesta</label>
          <input
            type="text"
            id="title"
            [(ngModel)]="survey.title"
            name="title"
            required
            class="form-control"
          />
        </div>
        
        <div class="form-group">
          <label for="description">Descripción</label>
          <textarea
            id="description"
            [(ngModel)]="survey.description"
            name="description"
            required
            class="form-control"
          ></textarea>
        </div>

        <div class="questions-section">
          <h3>Preguntas</h3>
          <button type="button" class="btn-secondary" (click)="addQuestion()">
            Añadir Pregunta
          </button>

          <div *ngFor="let question of questions; let i = index" class="question-item">
            <div class="form-group">
              <label>Texto de la Pregunta</label>
              <input
                type="text"
                [(ngModel)]="question.text"
                [name]="'question_' + i"
                class="form-control"
              />
            </div>
            
            <div class="form-group">
              <label>Tipo de Pregunta</label>
              <select
                [(ngModel)]="question.type"
                [name]="'type_' + i"
                class="form-control"
              >
                <option value="open">Respuesta Abierta</option>
                <option value="single">Elección Única</option>
                <option value="multiple">Elección Múltiple</option>
              </select>
            </div>

            <button type="button" class="btn-danger" (click)="removeQuestion(i)">
              Eliminar Pregunta
            </button>
          </div>
        </div>

        <button type="submit" class="btn-primary">Crear Encuesta</button>
      </form>
    </div>
  `,
  styles: [`
    .survey-create {
      max-width: 800px;
      margin: 2rem auto;
      padding: 2rem;
    }
    .form-group {
      margin-bottom: 1rem;
    }
    .form-control {
      width: 100%;
      padding: 0.5rem;
      margin-top: 0.25rem;
      border: 1px solid #ddd;
      border-radius: 4px;
    }
    .questions-section {
      margin-top: 2rem;
    }
    .question-item {
      margin-top: 1rem;
      padding: 1rem;
      border: 1px solid #ddd;
      border-radius: 4px;
    }
    .btn-primary, .btn-secondary, .btn-danger {
      padding: 0.5rem 1rem;
      border-radius: 4px;
      cursor: pointer;
      margin-right: 0.5rem;
    }
    .btn-primary {
      background-color: #007bff;
      color: white;
      border: none;
    }
    .btn-secondary {
      background-color: #6c757d;
      color: white;
      border: none;
    }
    .btn-danger {
      background-color: #dc3545;
      color: white;
      border: none;
    }
  `]
})
export class SurveyCreateComponent {
  survey = {
    title: '',
    description: ''
  };
  
  questions: Question[] = [];

  addQuestion() {
    this.questions.push({
      id: this.questions.length + 1,
      text: '',
      type: 'open'
    });
  }

  removeQuestion(index: number) {
    this.questions.splice(index, 1);
  }

  onSubmit() {
    console.log('Encuesta a crear:', {
      ...this.survey,
      questions: this.questions
    });
  }
}

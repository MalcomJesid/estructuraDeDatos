import { Component } from '@angular/core';
import { NgFor, NgIf } from '@angular/common';
import { RouterLink } from '@angular/router';
import { Survey } from '../../models/survey.model';

@Component({
  selector: 'app-lista-encuestas', 
  standalone: true,
  imports: [NgFor, NgIf, RouterLink],
  template: `
    <div class="survey-list">
      <div class="header">
        <h2>Encuestas</h2> 
        <button class="btn-primary" *ngIf="isAdmin" routerLink="/surveys/create">
          Crear Nueva Encuesta
        </button>
      </div>
      
      <div class="surveys-grid">
        <div *ngFor="let survey of surveys" class="survey-card">
          <h3>{{ survey.title }}</h3>
          <p>{{ survey.description }}</p>
          <div class="card-actions">
            <button class="btn-secondary" [routerLink]="['/surveys', survey.id]">
              Ver Detalles
            </button>
            <button class="btn-primary" [routerLink]="['/surveys', survey.id, 'configure']">
              Configurar
            </button>
          </div>
        </div>
      </div>
    </div>
  `,
  styles: [`
    .survey-list {
      padding: 2rem;
    }
    .header {
      display: flex;
      justify-content: space-between;
      align-items: center;
      margin-bottom: 2rem;
    }
    .surveys-grid {
      display: grid;
      grid-template-columns: repeat(auto-fill, minmax(300px, 1fr));
      gap: 1.5rem;
    }
    .survey-card {
      padding: 1.5rem;
      border-radius: 8px;
      box-shadow: 0 2px 4px rgba(0,0,0,0.1);
      background: white;
    }
    .card-actions {
      display: flex;
      gap: 1rem;
      margin-top: 1rem;
    }
    .btn-primary, .btn-secondary {
      padding: 0.5rem 1rem;
      border-radius: 4px;
      cursor: pointer;
    }
    .btn-primary {
      background-color: #007bff;
      color: white;
      border: none;
    }
    .btn-secondary {
      background-color: transparent;
      border: 1px solid #007bff;
      color: #007bff;
    }
  `]
})
export class SurveyListComponent {
  isAdmin = true; // Simulando si el usuario es administrador
  surveys: Survey[] = [
    {
      id: 1,
      title: 'Encuesta de Experiencia Estudiantil',
      description: 'Encuesta sobre la experiencia de los estudiantes en la institución',
      questions: [],
      createdAt: new Date()
    },
    {
      id: 2,
      title: 'Encuesta de Actividades Complementarias',
      description: 'Encuesta sobre la experiencia de los estudiantes en la institución',
      questions: [],
      createdAt: new Date()
    }
  ];
}
